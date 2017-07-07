#include"Term.h"

Term::Term(long long coefficient, char variable, long long exponent, Term* next)
{
    this->setCoefficient(coefficient);
    this->setVariable(variable);
    this->setExponent(exponent);
    this->setNext(next);
}

Term::~Term()
{
    this->setCoefficient(0);
    this->setVariable('\0');
    this->setExponent(0);
    this->setNext(NULL);
}

void Term::setCoefficient(long long coefficient)
{
    this->coefficient=coefficient;
}

long long Term::getCoefficient()
{
    return this->coefficient;
}

void Term::setVariable(char variable)
{
    this->variable=variable;
}

char Term::getVariable()
{
    return this->variable;
}

void Term::setExponent(long long exponent)
{
    this->exponent=exponent;
}

long long Term::getExponent()
{
    return this->exponent;
}

void Term::setNext(Term* next)
{
    this->next=next;
}

Term* Term::getNext()
{
    return this->next;
}
