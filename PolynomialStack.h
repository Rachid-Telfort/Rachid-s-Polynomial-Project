#ifndef POLYNOMIALSTACK_H_INCLUDED
#define POLYNOMIALSTACK_H_INCLUDED

#include"PolynomialStackNode.h"

class PolynomialStack
{
    private:
        PolynomialStackNode* top;

    public:
        PolynomialStack();
        ~PolynomialStack();
        void setTop(PolynomialStackNode*);
        PolynomialStackNode* getTop();
        void push(Polynomial*);
        void pop();
};

#endif//POLYNOMIALSTACK_H_INCLUDED
