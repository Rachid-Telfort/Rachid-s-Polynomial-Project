#include"NumberStackNode.h"

NumberStackNode::NumberStackNode(long double numberData, NumberStackNode* next)
{
    this->setNumberData(numberData);
    this->setNext(next);
}

NumberStackNode::~NumberStackNode()
{
    this->setNumberData(0);
    this->setNext(NULL);
}

void NumberStackNode::setNumberData(long double numberData)
{
    this->numberData=numberData;
}

long double NumberStackNode::getNumberData()
{
    return this->numberData;
}

void NumberStackNode::setNext(NumberStackNode* next)
{
    this->next=next;
}

NumberStackNode* NumberStackNode::getNext()
{
    return this->next;
}
