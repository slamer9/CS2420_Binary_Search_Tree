#include "BSTNode.h"

BSTNode::BSTNode(int data, BSTNode* left = nullptr, BSTNode* right = nullptr) //Templatize?
{
    this->data = data;
    this->left_ptr = left;
    this->right_ptr = right;
}

BSTNode::~BSTNode()
{

}

//MODIFICATION MEMBER FUNCTIONS *******
int& BSTNode::data()     //Templatize?
{
    return this->data;
}

BSTNode*& BSTNode::left()
{
    return this->left_ptr;
}

BSTNode*& BSTNode::right()
{
    return this->right_ptr;
}

void BSTNode::set_data()
{

}

void BSTNode::set_left()
{

}

void BSTNode::set_right()
{
    
}

//CONSTANT MEMBER FUNCTIONS *******
// const int& BSTNode::data()const     //Templatize? [ ] what is purpose of second const?
// {
//     return this->data;
// }

// const BSTNode* BSTNode::left()const //[ ] what is purpose of second const?
// {
//     return this->left_ptr;
// }

// const BSTNode* BSTNode::right()const
// {
//     return this->right_ptr;
// }

bool BSTNode::is_leaf()const
{
    return ((this->left_ptr == nullptr) && (this->right_ptr == nullptr));
}