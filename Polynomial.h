#ifndef POLYNOMIAL_H_INCLUDED
#define POLYNOMIAL_H_INCLUDED

#include<cmath>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<iostream>
#include<sstream>
#include"BinaryStack.h"
#include"NumberStack.h"
#include"Term.h"

class Polynomial
{
    private:
        long long numberOfTerms;//This is to keep track of the current number of terms in a polynomial.
        Term* head;//This points to the first term of a polynomial.

    public:
        Polynomial();
        Polynomial(Polynomial&);//This is the copy constructor used to make some operations on polynomials easier.
        Polynomial(long long);//This is to initialize an arbitrary polynomial. The user will enter the number of terms they want in the arbitrary polynomial. Then the arbitrary polynomial will be made using a random term generator.
        Polynomial(std::string);//This is to initialize a polynomial whose source is from a file.
        ~Polynomial();
        void setNumberOfTerms(long long);
        long long getNumberOfTerms();
        void setHead(Term*);
        Term* getHead();
        void push(Term*);//This is to add a term to a polynomial and sort it in the polynomial so that the polynomial will be sorted in terms of exponent order.
        friend std::istream& operator>>(std::istream&, Polynomial&);
        friend std::ostream& operator<<(std::ostream&, Polynomial&);
        Polynomial& operator=(Polynomial&);
        Polynomial& operator+(Polynomial&);
        Polynomial& operator-(Polynomial&);
        Polynomial& operator*(Polynomial&);
        Polynomial& operator/(Polynomial&);
        Polynomial& operator%(Polynomial&);
        void exponent(long long);
        void squareRoot();
        void factorial();
        void evaluate(long double);
        void zero(long double);//This function checks whether the input number is a zero of the polynomial or not.
        void allRationalZeros();//This function tries to find all possible rational zeros of the polynomial.
        void removeTerm(long long, char, long long);
        void inputFromFile(std::string);
        void ouputToFile(std::string);
};

#endif//POLYNOMIAL_H_INCLUDED
