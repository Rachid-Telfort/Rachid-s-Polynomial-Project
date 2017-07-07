#ifndef BINARYSTACKNODE_H_INCLUDED
#define BINARYSTACKNODE_H_INCLUDED

#include<iostream>

class BinaryStackNode//This class denotes an element that will be used in a stack representing the binary representation of a polynomial's exponentiation.
{
    private:
        int binaryData;
        BinaryStackNode* next;

    public:
        BinaryStackNode(int, BinaryStackNode*);
        ~BinaryStackNode();
        void setBinaryData(int);
        int getBinaryData();
        void setNext(BinaryStackNode*);
        BinaryStackNode* getNext();
};

#endif//BINARYSTACKNODE_H_INCLUDED
