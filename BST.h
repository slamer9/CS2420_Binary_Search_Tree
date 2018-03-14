#pragma once

///Temp
#include <vector>
#include <iostream>
#include <iomanip>
#include <cassert>

//#include <algorithm>
//include <functional>
#include <array>

using namespace std;

class BST
{
public:
    BST();
    ~BST();
    unsigned int Size();
    void Print();
    void Erase(int item);
    void Insert(int item);  //Don't allow duplcates
    void Traversals();  //FIX ME, PRE-ORDER, IN-ORDER, POST-ORDER
private:
    int root;       //WHAT DATA TYPE?
};