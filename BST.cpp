#include "BST.h"

/*Relevant pages in book:
528,
*/

BST::BST()
{
    this->list_size = 0;
    this->root = nullptr;
}

BST::~BST() //FIXME
{
    if(this->root != nullptr)
    {
        this->destructorHelper(this->root);
    }
}

void BST::destructorHelper(BSTNode* base)
{
    if(base->right() != nullptr)
    {
        destructorHelper(base->right());
    }
    if(base->left() != nullptr)
    {
        destructorHelper(base->left());
    }
    delete base;
}

unsigned int BST::size()
{
    return this->list_size;
}

int BST::getMax()
{
    BSTNode* temp = this->root;
    if(this->root->right() != nullptr)
    {
        temp = this->root;
        while(temp->right() != nullptr)//set parent of max, ->right = deleted thing ->right
        {
            temp = temp->right();
        }
        return temp->data();
    } else
    {
        return this->root->data();
    }
}

void BST::Print()
{
    this->Pre_order();
}

void BST::Erase(int value)
{
    if(this->root != nullptr)
    {
        this->erase_helper(this->root, nullptr, value);
    } else
    {
        cout << endl << "List is empty." << endl;
    }
}

void BST::erase_helper(BSTNode* base, BSTNode* parent, int value) //pointer reference?
{
    bool isRoot = (base == this->root);
    int baseData = base->data();

    if(!isRoot) //Debugging
    {
        if(! (base == parent->left() || base == parent->right()))
        {
            cout << "Your parent/base structure is wrong" << endl;
        }
    }

    if(baseData == value)   //Delete node
    {
        if(isRoot)  //Is root
        {
            if(base->left() == nullptr)           //Is left-less
            {
                this->root = base->right();
                delete base;
                --this->list_size;
                return;
            }else if(base->right() == nullptr)    //Is right-less
            {
                this->root = base->left();
                delete base;
                --this->list_size;
                return;
            }
            else                                 //Is fully linked node
            {
                BSTNode* temp = base;
                base = removeMaxUnder(base->left(), base);
                base->set_left(temp->left());
                base->set_right(temp->right());

                this->root = base;

                delete temp;
                this->list_size--;
                return;
            }
        }else if(base->right() == nullptr)  //Is right-less
        {
            if(parent->right() == base)
            {
                parent->rightReference() = base->left();
                delete base;
            }else if(parent->left() == base)
            {
                parent->leftReference() = base->left();
                delete base;
            }else
            {
                cout << endl << "Your parent logic failed" << endl; ///Debugging
            }
        }else if(base->left() == nullptr)   //Is left-less
        {
            if(parent->right() == base)
            {
                parent->rightReference() = base->right();
                delete base;
            }else if(parent->left() == base)
            {
                parent->leftReference() = base->right();
                delete base;
            }else
            {
                cout << endl << "Your parent logic failed" << endl; ///Debugging
            }
        }else                           //Is fully linked node
        {
            BSTNode* temp = base;
            base = removeMaxUnder(base->left(), base);
            base->set_left(temp->left());
            base->set_right(temp->right());

            //Link parent to base.
            if(parent->right() == temp)
            {
                parent->rightReference() = base;
            }else if(parent->left() == temp)
            {
                parent->leftReference() = base;
            }else
            {
                cout << endl << "Your parent logic failed" << endl; ///Debugging
            }

            delete temp;
            this->list_size--;
            return;
        }
    } else                  //Keep searching
    {
        if(value > baseData)
        {
            if(base->right() != nullptr)
            {
                erase_helper(base->right(), base, value);
            }
        }else if(value < baseData)
        {
            if(base->left() != nullptr)
            {
                erase_helper(base->left(), base, value);
            }
        }
    }
}

BSTNode* BST::removeMaxUnder(BSTNode* base, BSTNode* parent) //base, nothing to right. Doesn't delete, just rearanges pointers
{
    if(base != nullptr)
    {
        if(base->right() != nullptr)
        {
            while(base->right() != nullptr)//set parent of max, ->right = deleted thing ->right
            {
                parent = base;
                base = base->right();
            }
            parent->rightReference() = base->left();
        } else
        {
            parent->leftReference() = base->left();
        }
        base->leftReference() = nullptr;    //Not really necessary but makes it feel more complete to me
        return base;
    }
}

int BST::removeMax()
{
    int valRemoved = 0;
    if(this->root != nullptr)
    {
        BSTNode* temp = this->root;
        //BSTNode* parent = this->root;
        while(temp->right() != nullptr)
        {
            //parent = temp;
            temp = temp->right();
        }
        valRemoved = temp->data();
        this->Erase(temp->data());
    } else
    {
        cout << endl << "List is empty." << endl;   //Throw an exception to stop from displaying wrong stuff
                                                    //but not required for this project so ill add it if I 
                                                    //have time.
    }
    return valRemoved;
}

void BST::Insert(int value)
{
    if(this->root == nullptr)
    {
        this->root = new BSTNode(value);
        this->list_size++;
    } else
    {
        bool discard = false;
        bool left;
        BSTNode* temp = this->root;
        BSTNode* temp2 = nullptr;       

        while(temp != nullptr)
        {
            if(temp->data() > value)
            {
                temp2 = temp;
                temp = temp->left();
                left = true;
            } else if(temp->data() < value)
            {
                temp2 = temp;
                temp = temp->right();
                left = false;
            } else if(temp->data() == value)
            {
                discard = true;//discard value, no duplicates allowed.
                temp = nullptr;//to exit while loop
                cout << endl << "Value already in tree." << endl;
            } else
            {
                cout << endl << "Error" << endl;
            }
        }
        if(discard == false)
        {
            if(left == true)
            {
                temp2->leftReference() = new BSTNode(value);
            } else
            {
                temp2->rightReference() = new BSTNode(value);
            }
            this->list_size++;
        }
    }
}

void BST::Pre_order()//PRE-ORDER = mlr
{
    cout << endl;
    if(this->root != nullptr)
    {
        unsigned int depth = 0;
        preorder_helper(this->root, depth);
    }
}

void BST::preorder_helper(BSTNode* base, unsigned int depth)
{
    for(unsigned int i =0; i < depth; ++i)
    {
        cout << "\t";
    }
    cout << base->data() << endl;

    if(base->left() != nullptr)
    {
        preorder_helper(base->left(), depth+1);
    }

    if(base->right() != nullptr)
    {
        preorder_helper(base->right(), depth+1);
    }
}

void BST::In_order()//IN-ORDER = lmr
{
    cout << endl;
    if(this->root != nullptr)
    {
        unsigned int depth = 0;
        inorder_helper(this->root, depth);
    }
}

void BST::inorder_helper(BSTNode* base, unsigned int depth)
{
    if(base->left() != nullptr)
    {
        inorder_helper(base->left(), depth+1);
    }

    for(unsigned int i =0; i < depth; ++i)
    {
        cout << "\t";
    }
    cout << base->data() << endl;

    if(base->right() != nullptr)
    {
        inorder_helper(base->right(), depth+1);
    }
}

void BST::Post_order()//POST-ORDER = lrm
{
    cout << endl;
    if(this->root != nullptr)
    {
        unsigned int depth = 0;
        postorder_helper(this->root, depth);
    }
}

void BST::postorder_helper(BSTNode* base, unsigned int depth)
{
    if(base->left() != nullptr)
    {
        postorder_helper(base->left(), depth+1);
    }

    if(base->right() != nullptr)
    {
        postorder_helper(base->right(), depth+1);
    }

    for(unsigned int i =0; i < depth; ++i)
    {
        cout << "\t";
    }
    cout << base->data() << endl;
}