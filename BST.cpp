#include "BST.h"

BST::BST()
{

}

BST::~BST()
{

}

unsigned int BST::Size()
{

}

void BST::Print()
{
    BSTNode* temp = this->root;
    unsigned int depth = 0;
    cout << "\n";

    if(temp != nullptr)
    {
        for(unsigned int i = 0; i < depth; ++i)
        {
            cout << "\t";
        }
        cout << temp->data();   //NOT FINISHED
    }
}

void BST::Erase(int item)
{

}

void BST::Insert(int item)
{

}