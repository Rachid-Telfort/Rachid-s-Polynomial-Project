#ifndef NUMBERSTACK_H_INCLUDED
#define NUMBERSTACK_H_INCLUDED

#include"NumberStackNode.h"

class NumberStack
{
    private:
        NumberStackNode* top;

    public:
        NumberStack();
        ~NumberStack();
        void setTop(NumberStackNode*);
        NumberStackNode* getTop();
        void push(long double);
        void pop();
};

#endif//NUMBERSTACK_H_INCLUDED
