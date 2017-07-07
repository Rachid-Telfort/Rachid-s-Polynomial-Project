#ifndef NUMBERSTACKNODE_H_INCLUDED
#define NUMBERSTACKNODE_H_INCLUDED

#include<iostream>

class NumberStackNode//This class denotes an element of a stack that will be used to uncover certain properties pertaining to polynomials.
{
    private:
        long double numberData;
        NumberStackNode* next;

    public:
        NumberStackNode(long double, NumberStackNode*);
        ~NumberStackNode();
        void setNumberData(long double);
        long double getNumberData();
        void setNext(NumberStackNode*);
        NumberStackNode* getNext();
};

#endif//NUMBERSTACKNODE_H_INCLUDED
