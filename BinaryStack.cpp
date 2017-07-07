#include"BinaryStack.h"

BinaryStack::BinaryStack()
{
    this->setTop(NULL);
}

BinaryStack::~BinaryStack()
{
    while(this->getTop()!=NULL)
    {
        BinaryStackNode* clearStackNode=this->getTop();
        this->setTop(this->getTop()->getNext());
        delete clearStackNode;
        clearStackNode=NULL;
    }
}

void BinaryStack::setTop(BinaryStackNode* top)
{
    this->top=top;
}

BinaryStackNode* BinaryStack::getTop()
{
    return this->top;
}

void BinaryStack::push(int binaryData)
{
    if(this->getTop()==NULL)
    {
        this->setTop(new BinaryStackNode(binaryData, NULL));
    }

    else
    {
        BinaryStackNode* newStackNode=new BinaryStackNode(binaryData, this->getTop());
        this->setTop(newStackNode);
    }
}

void BinaryStack::pop()
{
    if(this->getTop()==NULL)
    {
        std::cout<<"The binary stack is empty. There are no elements to pop from the binary stack.\n"<<std::endl;
    }

    else
    {
        BinaryStackNode* popStackNode=this->getTop();
        this->setTop(this->getTop()->getNext());
        delete popStackNode;
        popStackNode=NULL;
    }
}
