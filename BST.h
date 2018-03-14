#pragma once

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
                        //MLR= pre, LRM = post, LMR = in.
private:
    int root;       //WHAT DATA TYPE?
    unsigned int size;
};