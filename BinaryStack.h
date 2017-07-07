#ifndef BINARYSTACK_H_INCLUDED
#define BINARYSTACK_H_INCLUDED

#include"BinaryStackNode.h"

class BinaryStack
{
    private:
        BinaryStackNode* top;

    public:
        BinaryStack();
        ~BinaryStack();
        void setTop(BinaryStackNode*);
        BinaryStackNode* getTop();
        void push(int);
        void pop();
};

#endif//BINARYSTACK_H_INCLUDED
