#include"BinaryStackNode.h"

BinaryStackNode::BinaryStackNode(int binaryData, BinaryStackNode* next)
{
    this->setBinaryData(binaryData);
    this->setNext(next);
}

BinaryStackNode::~BinaryStackNode()
{
    this->setBinaryData(0);
    this->setNext(NULL);
}

void BinaryStackNode::setBinaryData(int binaryData)
{
    this->binaryData=binaryData;
}

int BinaryStackNode::getBinaryData()
{
    return this->binaryData;
}

void BinaryStackNode::setNext(BinaryStackNode* next)
{
    this->next=next;
}

BinaryStackNode* BinaryStackNode::getNext()
{
    return this->next;
}
