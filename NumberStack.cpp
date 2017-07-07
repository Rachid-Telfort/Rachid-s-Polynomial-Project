#include"NumberStack.h"

NumberStack::NumberStack()
{
    this->setTop(NULL);
}

NumberStack::~NumberStack()
{
    while(this->getTop()!=NULL)
    {
        NumberStackNode* clearStackNode=this->getTop();
        this->setTop(this->getTop()->getNext());
        delete clearStackNode;
        clearStackNode=NULL;
    }
}

void NumberStack::setTop(NumberStackNode* top)
{
    this->top=top;
}

NumberStackNode* NumberStack::getTop()
{
    return this->top;
}

void NumberStack::push(long double numberData)
{
    if(this->getTop()==NULL)
    {
        this->setTop(new NumberStackNode(numberData, NULL));
    }

    else
    {
        NumberStackNode* newStackNode=new NumberStackNode(numberData, this->getTop());
        this->setTop(newStackNode);
    }
}

void NumberStack::pop()
{
    if(this->getTop()==NULL)
    {
        std::cout<<"The number stack is empty. There are no elements to pop from the number stack.\n"<<std::endl;
    }

    else
    {
        NumberStackNode* popStackNode=this->getTop();
        this->setTop(this->getTop()->getNext());
        delete popStackNode;
        popStackNode=NULL;
    }
}
