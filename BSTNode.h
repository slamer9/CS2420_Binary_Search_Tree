#pragma once
///Temp
#include <vector>
#include <iostream>
#include <iomanip>
#include <cassert>

#include <array>


using namespace std;


class BSTNode
{
public:
    //int Item;     //Templatize?
    BSTNode(int data, BSTNode* left = nullptr, BSTNode* right = nullptr) //Templatize?
    {
        this->data = data;
        this->left_ptr = left;
        this->right_ptr = right;
    }
    ~BSTNode();

    //MODIFICATION MEMBER FUNCTIONS *******
    int& data()     //Templatize?
    {
        return this->data;
    }

    BSTNode*& left()
    {
        return this->left_ptr;
    }

    BSTNode*& right()
    {
        return this->right_ptr;
    }

    void set_data()
    {

    }

    void set_left()
    {

    }

    void set_right()
    {
        
    }

    //CONSTANT MEMBER FUNCTIONS *******
    const int& data()const     //Templatize? [ ] what is purpose of second const?
    {
        return this->data;
    }

    const BSTNode* left()const //[ ] what is purpose of second const?
    {
        return this->left_ptr;
    }

    const BSTNode* right()const
    {
        return this->right_ptr;
    }

    bool is_leaf()const
    {
        return ((this->left_ptr == nullptr) && (this->right_ptr == nullptr));
    }
    

private:
    int data;       //Templatize?
    BSTNode* left_ptr;
    BSTNode* right_ptr;
};