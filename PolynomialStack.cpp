#include"PolynomialStack.h"

PolynomialStack::PolynomialStack()
{
    this->setTop(NULL);
}

PolynomialStack::~PolynomialStack()
{
    while(this->getTop()!=NULL)
    {
        PolynomialStackNode* clearStackNode=this->getTop();
        this->setTop(this->getTop()->getNext());
        delete clearStackNode;
        clearStackNode=NULL;
    }
}

void PolynomialStack::setTop(PolynomialStackNode* top)
{
    this->top=top;
}

PolynomialStackNode* PolynomialStack::getTop()
{
    return this->top;
}

void PolynomialStack::push(Polynomial* P)
{
    if(this->getTop()==NULL)
    {
        this->setTop(new PolynomialStackNode(P, NULL));
    }

    else
    {
        PolynomialStackNode* newStackNode=new PolynomialStackNode(P, this->getTop());
        this->setTop(newStackNode);
    }
}

void PolynomialStack::pop()
{
    if(this->getTop()==NULL)
    {
        std::cout<<"The polynomial stack is empty. There are no elements to pop from the polynomial stack.\n"<<std::endl;
    }

    else
    {
        PolynomialStackNode* popStackNode=this->getTop();
        this->setTop(this->getTop()->getNext());
        delete popStackNode;
        popStackNode=NULL;
    }
}
