#include "BSTNode.h"

BSTNode::BSTNode(int data, BSTNode* left = nullptr, BSTNode* right = nullptr) //Templatize?
{
    this->nodeData = data;
    this->left_ptr = left;
    this->right_ptr = right;
}

BSTNode::~BSTNode()
{

}

//MODIFICATION MEMBER FUNCTIONS *******
int& BSTNode::data()     //Templatize?
{
    return this->nodeData;
}

BSTNode*& BSTNode::left()
{
    return this->left_ptr;
}

BSTNode*& BSTNode::right()
{
    return this->right_ptr;
}

void BSTNode::set_data(int newData)     //Templatize?
{
    this->nodeData;
}

void BSTNode::set_left(BSTNode* left)
{
    this->left_ptr = left;
}

void BSTNode::set_right(BSTNode* right)
{
    this->right_ptr = right;
}

bool BSTNode::is_leaf()const
{
    return ((this->left_ptr == nullptr) && (this->right_ptr == nullptr));
}