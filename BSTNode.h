#pragma once
///Temp
#include <vector>
#include <iostream>
#include <iomanip>
#include <cassert>

//#include <array>


using namespace std;


class BSTNode
{
public:
    //int Item;     //Templatize?
    BSTNode(int data, BSTNode* left = nullptr, BSTNode* right = nullptr); //Templatize?
    ~BSTNode();

    //MODIFICATION MEMBER FUNCTIONS *******
    int& data();     //Templatize?
    BSTNode* left();
    BSTNode* right();
    BSTNode*& leftReference();
    BSTNode*& rightReference();
    
    void set_data(int newData);
    void set_left(BSTNode* left);
    void set_right(BSTNode* right);

    //CONSTANT MEMBER FUNCTIONS *******
    // const int& data()const;     //Templatize? [ ] what is purpose of second const?
    // const BSTNode* left()const; //[ ] what is purpose of second const? (in book p:486)
    // const BSTNode* right()const;
    bool is_leaf()const;

private:
    int nodeData;       //Templatize?
    BSTNode* left_ptr;
    BSTNode* right_ptr;
};