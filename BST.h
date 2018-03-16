#pragma once

#include "BSTNode.h"

class BST
{
public:
    BST();
    ~BST();

    unsigned int size();

    void Print();

    void Erase(int value);

    BSTNode* removeMaxUnder(BSTNode* base, BSTNode* parent);    //Erase helper
    BSTNode* removeMax();
    int getMax();                                               //Added because why not.

    void Insert(int value);  //Don't allow duplcates

    void Pre_order();   //PRE-ORDER = mlr
    void In_order();    //IN-ORDER = lmr
    void Post_order();  //POST-ORDER = lrm
    
private:
    void destructorHelper(BSTNode* base);

    void erase_helper(BSTNode*& base, int value);

    void preorder_helper(BSTNode* base, unsigned int depth);
    void inorder_helper(BSTNode* base, unsigned int depth);
    void postorder_helper(BSTNode* base, unsigned int depth);

    BSTNode* root;       //WHAT DATA TYPE?
    unsigned int list_size;
};