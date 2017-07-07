#include"PolynomialStackNode.h"

PolynomialStackNode::PolynomialStackNode(Polynomial* P, PolynomialStackNode* next)
{
    this->setP(P);
    this->setNext(next);
}

PolynomialStackNode::~PolynomialStackNode()
{
    delete this->getP();
    this->setP(NULL);
    this->setNext(NULL);
}

void PolynomialStackNode::setP(Polynomial* P)
{
    if(P!=NULL)
    {
        this->P=new Polynomial(*P);
    }

    else
    {
        this->P=NULL;
    }
}

Polynomial* PolynomialStackNode::getP()
{
    return this->P;
}

void PolynomialStackNode::setNext(PolynomialStackNode* next)
{
    this->next=next;
}

PolynomialStackNode* PolynomialStackNode::getNext()
{
    return this->next;
}
