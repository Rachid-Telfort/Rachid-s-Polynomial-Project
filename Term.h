#ifndef TERM_H_INCLUDED
#define TERM_H_INCLUDED

#include<cstddef>

class Term
{
    private:
        long long coefficient;
        char variable;
        long long exponent;
        Term* next;

    public:
        Term(long long, char, long long, Term*);
        ~Term();
        void setCoefficient(long long);
        long long getCoefficient();
        void setVariable(char);
        char getVariable();
        void setExponent(long long);
        long long getExponent();
        void setNext(Term*);
        Term* getNext();
};

#endif//TERM_H_INCLUDED
