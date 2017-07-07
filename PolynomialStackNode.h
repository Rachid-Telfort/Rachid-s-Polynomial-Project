#ifndef POLYNOMIALSTACKNODE_H_INCLUDED
#define POLYNOMIALSTACKNODE_H_INCLUDED

#include"Polynomial.h"

class PolynomialStackNode//This class denotes an element that will be used in a stack of polynomials.
{
    private:
        Polynomial* P;
        PolynomialStackNode* next;

    public:
        PolynomialStackNode(Polynomial*, PolynomialStackNode*);
        ~PolynomialStackNode();
        void setP(Polynomial*);
        Polynomial* getP();
        void setNext(PolynomialStackNode*);
        PolynomialStackNode* getNext();
};

#endif//POLYNOMIALSTACKNODE_H_INCLUDED


