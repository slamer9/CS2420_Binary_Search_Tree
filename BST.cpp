#include "BST.h"

/*Relevant pages in book:
528,
*/

BST::BST()
{
    this->list_size = 0;
    this->root = nullptr;
}

BST::~BST()
{

}

unsigned int BST::size()
{
    return this->list_size;
}

void BST::Print()
{
    this->Pre_order();
}

void BST::Erase(int value)
{
    if(this->root != nullptr)
    {
        this->erase_helper(this->root, value);
    }
}

void BST::erase_helper(BSTNode*& base, int value) //pointer reference?
{
    BSTNode* temp;
    int baseData = base->data();

    if(baseData == value)
    {
        if(base->right() == nullptr)
        {
            if(base->left() != nullptr)
            {
                temp = base;
                base = base->left;
                delete temp;
                return;
            }
        } else if(base->left() == nullptr)
        {
            if(base->right() != nullptr)
            {
                temp = base;
                base = base->right();
                delete temp;
                return;
            }
        } else //delete a node where both branches have values
        {
            temp = base;
            base = removeMaxUnder(base->left());//FIXME
            base->set_left(temp->left());
            base->set_right(temp->right());
            delete temp;

            return;//?
        }
    }else if(baseData < value)
    {
        if(base->right() != nullptr)
        {
            erase_helper(base->right(), value);
        }
    }else if(baseData > value)
    {
        if(base->left() != nullptr)
        {
            erase_helper(base->left(), value);
        }
    }
}

BSTNode* BST::removeMaxUnder(BSTNode* base) //base, nothing to right. Doesn't delete, just rearanges pointers
{
    while(base->right())//set parent of max, ->right = deleted thing ->right

}

void BST::Insert(int value)
{
    if(this->root == nullptr)
    {
        this->root = new BSTNode(value);
    } else
    {
        bool discard = false;
        bool left;
        BSTNode* temp = this->root;
        BSTNode* temp2 = nullptr;       

        while(temp != nullptr)
        {
            if(temp->data() < value)
            {
                temp2 = temp;
                temp = temp->left();
                left = true;
            } else if(temp->data() > value)
            {
                temp2 = temp;
                temp = temp->right();
                left = false;
            } else if(temp->data() == value)
            {
                discard = true;//discard value, no duplicates allowed.
                temp = nullptr;//to exit while loop
            } else
            {
                cout << endl << "Error" << endl;
            }
        }
        if(discard == false)
        {
            if(left = true)
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

void preorder_helper(BSTNode* base, unsigned int depth)
{
    for(unsigned int i =0; i < depth; ++i)
    {
        cout << "\t";
    }
    cout << base->data() << endl;

    if(base->left() != nullptr)
    {
        inorder_helper(base->left(), depth+1);
    }

    if(base->right() != nullptr)
    {
        inorder_helper(base->right(), depth+1);
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

void inorder_helper(BSTNode* base, unsigned int depth)
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

void postorder_helper(BSTNode* base, unsigned int depth)
{
    if(base->left() != nullptr)
    {
        inorder_helper(base->left(), depth+1);
    }

    if(base->right() != nullptr)
    {
        inorder_helper(base->right(), depth+1);
    }

    for(unsigned int i =0; i < depth; ++i)
    {
        cout << "\t";
    }
    cout << base->data() << endl;
}