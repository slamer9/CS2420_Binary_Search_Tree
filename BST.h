#pragma once

#include "BSTNode.h"

class BST
{
public:
    BST();
    ~BST();
    unsigned int Size();
    void Print();
    void Erase(int item);
    void Insert(int item);  //Don't allow duplcates
    void Traversals();  //FIX ME, PRE-ORDER = mlr, IN-ORDER = lmr, POST-ORDER = lrm
private:
    BSTNode* root;       //WHAT DATA TYPE?
    unsigned int size;
};