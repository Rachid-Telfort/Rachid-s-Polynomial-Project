#include"Polynomial.h"
#include"PolynomialStack.h"

Polynomial::Polynomial()
{
    this->setNumberOfTerms(0);
    this->setHead(NULL);
}

Polynomial::Polynomial(Polynomial& P)
{
    this->setNumberOfTerms(0);
    this->setHead(NULL);

    Term* copyTerm=P.getHead();
    while(copyTerm!=NULL)
    {
        Term* copyTerm2=new Term(copyTerm->getCoefficient(), copyTerm->getVariable(), copyTerm->getExponent(), NULL);
        this->push(copyTerm2);
        copyTerm=copyTerm->getNext();
    }
}

Polynomial::Polynomial(long long numberOfTerms)
{
    this->setNumberOfTerms(0);
    this->setHead(NULL);

    std::srand(time(NULL));
    char variable='a'+std::rand()%26;

    for(long long termCount=0; termCount<numberOfTerms; termCount++)
    {
        long long coefficient=std::rand()%100;
        long long exponent=std::rand()%100;
        Term* arbitraryTerm=new Term(coefficient, variable, exponent, NULL);
        this->push(arbitraryTerm);
    }
}

Polynomial::Polynomial(std::string pFileName)
{
    this->setNumberOfTerms(0);
    this->setHead(NULL);

    std::fstream pFileStream(pFileName.c_str());
    if(pFileStream.is_open())
    {
        std::string pFileInsert=std::string();
        while(pFileStream>>pFileInsert)
        {
            std::stringstream pFileInsertSS(pFileInsert);
            pFileInsertSS>>*this;
        }

        std::cout<<"The polynomial from the file "<<pFileName<<" has successfully been loaded into the working polynomial.\n"<<std::endl;
    }

    else
    {
        std::cout<<"The file "<<pFileName<<" could not be opened to load the polynomial from it. An empty polynomial will be now be initialized instead. If you wish to load a polynomial from a file again you will be able to do so in the program.\n"<<std::endl;
    }

    pFileStream.close();
}

Polynomial::~Polynomial()
{
    this->setNumberOfTerms(0);

    while(this->getHead()!=NULL)
    {
        Term* clearTerm=this->getHead();
        this->setHead(this->getHead()->getNext());
        delete clearTerm;
        clearTerm=NULL;
    }
}

void Polynomial::setNumberOfTerms(long long numberOfTerms)
{
    this->numberOfTerms=numberOfTerms;
}

long long Polynomial::getNumberOfTerms()
{
    return this->numberOfTerms;
}

void Polynomial::setHead(Term* head)
{
    this->head=head;
}

Term* Polynomial::getHead()
{
    return this->head;
}

void Polynomial::push(Term* newTerm)
{
    if(newTerm->getCoefficient()==0)
    {
        delete newTerm;
        newTerm=NULL;
    }

    else if(this->getHead()==NULL)
    {
        this->setHead(newTerm);
        this->setNumberOfTerms(this->getNumberOfTerms()+1);
        newTerm=NULL;
    }

    else
    {
        Term* pushTerm=this->getHead();
        Term* pushTerm2=this->getHead();
        while(pushTerm2!=NULL)
        {
            if(pushTerm2->getExponent()<newTerm->getExponent())
            {
                if(pushTerm2==this->getHead())
                {
                    newTerm->setNext(pushTerm2);
                    this->setHead(newTerm);
                    this->setNumberOfTerms(this->getNumberOfTerms()+1);
                    newTerm=NULL;
                    pushTerm=NULL;
                    pushTerm2=NULL;
                }

                else
                {
                    pushTerm->setNext(newTerm);
                    newTerm->setNext(pushTerm2);
                    this->setNumberOfTerms(this->getNumberOfTerms()+1);
                    newTerm=NULL;
                    pushTerm=NULL;
                    pushTerm2=NULL;
                }
            }

            else if(pushTerm2->getExponent()>newTerm->getExponent())
            {
                if(pushTerm2->getNext()==NULL)
                {
                    pushTerm2->setNext(newTerm);
                    this->setNumberOfTerms(this->getNumberOfTerms()+1);
                    newTerm=NULL;
                    pushTerm=NULL;
                    pushTerm2=NULL;
                }

                else
                {
                    pushTerm=pushTerm2;
                    pushTerm2=pushTerm2->getNext();
                }
            }

            else
            {
                pushTerm2->setCoefficient(pushTerm2->getCoefficient()+newTerm->getCoefficient());
                delete newTerm;
                newTerm=NULL;

                if(pushTerm2->getCoefficient()==0)
                {
                    if(pushTerm2->getNext()==NULL)
                    {
                        if(pushTerm2==this->getHead())
                        {
                            delete pushTerm2;
                            this->setHead(NULL);
                            pushTerm=NULL;
                            pushTerm2=NULL;
                        }

                        else
                        {
                            pushTerm->setNext(NULL);
                            delete pushTerm2;
                            pushTerm=NULL;
                            pushTerm2=NULL;
                        }
                    }

                    else
                    {
                        if(pushTerm2==this->getHead())
                        {
                            this->setHead(this->getHead()->getNext());
                            delete pushTerm2;
                            pushTerm=NULL;
                            pushTerm2=NULL;
                        }

                        else
                        {
                            pushTerm->setNext(pushTerm2->getNext());
                            delete pushTerm2;
                            pushTerm=NULL;
                            pushTerm2=NULL;
                        }
                    }

                    this->setNumberOfTerms(this->getNumberOfTerms()-1);
                }

                else
                {
                    pushTerm=NULL;
                    pushTerm2=NULL;
                }
            }
        }
    }
}

std::istream& operator>>(std::istream& is, Polynomial& P)
{
    long long coefficient=0;
    char variable='\0';
    long long exponent=0;

    is>>coefficient>>variable>>exponent;

    if(variable<97||variable>122)
    {
        std::srand(time(NULL));
        variable='a'+std::rand()%26;
    }

    if(P.getHead()!=NULL)
    {
        variable=P.getHead()->getVariable();
    }

    Term* isTerm=new Term(coefficient, variable, exponent, NULL);
    P.push(isTerm);

    return is;
}

std::ostream& operator<<(std::ostream& os, Polynomial& P)
{
    Term* osTerm=P.getHead();
    while(osTerm!=NULL)
    {
        os<<osTerm->getCoefficient()<<osTerm->getVariable()<<osTerm->getExponent()<<" ";
        osTerm=osTerm->getNext();
    }
    os<<std::endl;

    return os;
}

Polynomial& Polynomial::operator=(Polynomial& P)
{
    if(this!=&P)//This checks for self-assignment.
    {
        if(this->getHead()!=NULL)
        {
            this->setNumberOfTerms(0);

            while(this->getHead()!=NULL)
            {
                Term* clearTerm=this->getHead();
                this->setHead(this->getHead()->getNext());
                delete clearTerm;
                clearTerm=NULL;
            }
        }

        Term* assignTerm=P.getHead();
        while(assignTerm!=NULL)
        {
            Term* assignTerm2=new Term(assignTerm->getCoefficient(), assignTerm->getVariable(), assignTerm->getExponent(), NULL);
            this->push(assignTerm2);
            assignTerm=assignTerm->getNext();
        }
    }

    return *this;
}

Polynomial& Polynomial::operator+(Polynomial& P)
{
    Polynomial* augend=new Polynomial(*this);
    Polynomial* addend=new Polynomial(P);
    Polynomial* sum=new Polynomial();

    Term* addTerm=augend->getHead();
    while(addTerm!=NULL)
    {
        Term* addTerm2=new Term(addTerm->getCoefficient(), addTerm->getVariable(), addTerm->getExponent(), NULL);
        sum->push(addTerm2);
        addTerm=addTerm->getNext();
    }

    addTerm=addend->getHead();
    while(addTerm!=NULL)
    {
        Term* addTerm2=new Term(addTerm->getCoefficient(), addTerm->getVariable(), addTerm->getExponent(), NULL);
        sum->push(addTerm2);
        addTerm=addTerm->getNext();
    }

    delete augend;
    augend=NULL;

    delete addend;
    addend=NULL;

    return *sum;
}

Polynomial& Polynomial::operator-(Polynomial& P)
{
    Polynomial* minuend=new Polynomial(*this);
    Polynomial* subtrahend=new Polynomial(P);
    Polynomial* difference=new Polynomial();

    Term* subtractTerm=minuend->getHead();
    while(subtractTerm!=NULL)
    {
        Term* subtractTerm2=new Term(subtractTerm->getCoefficient(), subtractTerm->getVariable(), subtractTerm->getExponent(), NULL);
        difference->push(subtractTerm2);
        subtractTerm=subtractTerm->getNext();
    }

    subtractTerm=subtrahend->getHead();
    while(subtractTerm!=NULL)
    {
        Term* subtractTerm2=new Term(-subtractTerm->getCoefficient(), subtractTerm->getVariable(), subtractTerm->getExponent(), NULL);
        difference->push(subtractTerm2);
        subtractTerm=subtractTerm->getNext();
    }

    delete minuend;
    minuend=NULL;

    delete subtrahend;
    subtrahend=NULL;

    return *difference;
}

Polynomial& Polynomial::operator*(Polynomial& P)
{
    Polynomial* multiplicand=new Polynomial(*this);
    Polynomial* multiplier=new Polynomial(P);
    Polynomial* product=new Polynomial();

    Term* multiplyTerm=multiplicand->getHead();
    Term* multiplyTerm2=multiplier->getHead();
    while(multiplyTerm!=NULL)
    {
        while(multiplyTerm2!=NULL)
        {
            Term* multiplyTerm3=new Term(multiplyTerm->getCoefficient()*multiplyTerm2->getCoefficient(), multiplyTerm->getVariable(), multiplyTerm->getExponent()+multiplyTerm2->getExponent(), NULL);
            product->push(multiplyTerm3);
            multiplyTerm2=multiplyTerm2->getNext();
        }

        multiplyTerm=multiplyTerm->getNext();
        if(multiplyTerm!=NULL)
        {
            multiplyTerm2=multiplier->getHead();
        }
    }

    delete multiplicand;
    multiplicand=NULL;

    delete multiplier;
    multiplier=NULL;

    return *product;
}

Polynomial& Polynomial::operator/(Polynomial& P)
{
    Polynomial* quotient=new Polynomial();

    if(P.getHead()==NULL)
    {
        std::cout<<"The division cannot be done between the dividend polynomial and the divisor polynomial because the divisor polynomial has zero value and division by zero is undefined.\n"<<std::endl;
    }

    else
    {
        Polynomial* dividend=new Polynomial(*this);
        Polynomial* divisor=new Polynomial(P);
        Polynomial* factor=new Polynomial();

        Term* divideTerm=dividend->getHead();
        Term* divideTerm2=divisor->getHead();
        while(divideTerm!=NULL)
        {
            Term* divideTerm3=new Term(divideTerm->getCoefficient()/divideTerm2->getCoefficient(), divideTerm->getVariable(), divideTerm->getExponent()-divideTerm2->getExponent(), NULL);
            quotient->push(divideTerm3);

            Term* divideTerm4=new Term(divideTerm->getCoefficient()/divideTerm2->getCoefficient(), divideTerm->getVariable(), divideTerm->getExponent()-divideTerm2->getExponent(), NULL);
            factor->push(divideTerm4);

            *dividend=*dividend-*factor**divisor;

            delete factor;
            factor=NULL;

            divideTerm=dividend->getHead();
            if(divideTerm!=NULL)
            {
                if(abs(divideTerm->getExponent())<abs(divideTerm2->getExponent())||abs(divideTerm->getCoefficient())<abs(divideTerm2->getCoefficient())||dividend->getNumberOfTerms()<divisor->getNumberOfTerms())
                {
                    divideTerm=NULL;
                }

                else
                {
                    factor=new Polynomial();
                }
            }
        }

        delete dividend;
        dividend=NULL;

        delete divisor;
        divisor=NULL;
    }

    return *quotient;
}

Polynomial& Polynomial::operator%(Polynomial& P)
{
    Polynomial* modulus=new Polynomial();

    if(P.getHead()==NULL)
    {
        std::cout<<"The modulus cannot be done between the dividend polynomial and the divisor polynomial because the divisor polynomial has zero value and modulus by zero is undefined.\n"<<std::endl;
    }

    else
    {
        *modulus=*this;
        Polynomial* divisor=new Polynomial(P);
        Polynomial* factor=new Polynomial();

        Term* modTerm=modulus->getHead();
        Term* modTerm2=divisor->getHead();
        while(modTerm!=NULL)
        {
            Term* modTerm3=new Term(modTerm->getCoefficient()/modTerm2->getCoefficient(), modTerm->getVariable(), modTerm->getExponent()-modTerm2->getExponent(), NULL);
            factor->push(modTerm3);

            *modulus=*modulus-*factor**divisor;

            delete factor;
            factor=NULL;

            modTerm=modulus->getHead();
            if(modTerm!=NULL)
            {
                if(abs(modTerm->getExponent())<abs(modTerm2->getExponent())||abs(modTerm->getCoefficient())<abs(modTerm2->getCoefficient())||modulus->getNumberOfTerms()<divisor->getNumberOfTerms())
                {
                    modTerm=NULL;
                }

                else
                {
                    factor=new Polynomial();
                }
            }
        }

        delete divisor;
        divisor=NULL;
    }

    return *modulus;
}

void Polynomial::exponent(long long exponent)
{
    if(exponent==0)
    {
        if(this->getHead()==NULL)
        {
            std::srand(time(NULL));
            char variable='a'+std::rand()%26;
            this->setHead(new Term(1, variable, 0, NULL));
        }

        else
        {
            Term* exponentTerm=new Term(1, this->getHead()->getVariable(), 0, NULL);
            Polynomial* P=new Polynomial();
            P->push(exponentTerm);
            *this=*P;

            delete P;
            P=NULL;
        }
    }

    else
    {
        if(this->getHead()!=NULL)
        {
            bool isNegativeExponent=false;
            Polynomial* P=new Polynomial(*this);
            PolynomialStack* pStack=new PolynomialStack();
            BinaryStack* bStack=new BinaryStack();

            if(exponent<0)
            {
                isNegativeExponent=true;
                exponent*=-1;
            }

            while(exponent>=1)
            {
                int binaryBit=exponent%2;
                pStack->push(P);
                bStack->push(binaryBit);
                *P=*P**P;
                exponent/=2;
            }

            Term* exponentTerm=new Term(1, this->getHead()->getVariable(), 0, NULL);

            this->setNumberOfTerms(0);

            while(this->getHead()!=NULL)
            {
                Term* clearTerm=this->getHead();
                this->setHead(this->getHead()->getNext());
                delete clearTerm;
                clearTerm=NULL;
            }

            this->push(exponentTerm);

            while(pStack->getTop()!=NULL&&bStack->getTop()!=NULL)
            {
                if(bStack->getTop()->getBinaryData()==1)
                {
                    *this=*this**pStack->getTop()->getP();
                }

                pStack->pop();
                bStack->pop();
            }

            if(isNegativeExponent==true)
            {
                Polynomial* P2=new Polynomial();
                Term* exponentTerm2=new Term(1, this->getHead()->getVariable(), 0, NULL);
                P2->push(exponentTerm2);
                *this=*P2/(*this);

                delete P2;
                P2=NULL;
            }

            delete P;
            P=NULL;

            delete pStack;
            pStack=NULL;

            delete bStack;
            bStack=NULL;
        }

        else
        {
            std::cout<<"The polynomial is empty. Therefore its exponent result is 0.\n"<<std::endl;
        }
    }
}

void Polynomial::squareRoot()
{
    if(this->getHead()==NULL)
    {
        std::cout<<"The polynomial is empty. Thus its square root is 0.\n"<<std::endl;
    }

    else
    {
        if(this->getHead()->getExponent()==0)//This is the case where you have a normal number.
        {
            if(this->getHead()->getCoefficient()>0)//This checks to see if you have a positive number as you cannot take the square root of a negative number.
            {
                bool isRoot=false;
                bool isNotRoot=false;
                long long base=0;
                long long base2=0;
                while(isRoot==false&&isNotRoot==false)
                {
                   base2=base;
                   for(long long exponent=0; exponent<2-1; exponent++)
                   {
                        base2*=base;
                   }

                   if(base2==this->getHead()->getCoefficient())
                   {
                       isRoot=true;
                   }

                   else if(base==this->getHead()->getCoefficient())
                   {
                       isNotRoot=true;
                   }

                   else
                   {
                       base++;
                   }
                }

                if(isRoot==true)
                {
                    this->getHead()->setCoefficient(base);
                }

                else
                {
                    std::cout<<"The polynomial "<<*this<<" does not have a square root.\n"<<std::endl;
                }
            }

            else
            {
                std::cout<<"You cannot take the square root of "<<*this<<" as taking the square root of a negative number is undefined.\n"<<std::endl;
            }
        }

        else//This is the case where you do not have a normal number. Instead, the terms have actual exponents.
        {
            if(this->getNumberOfTerms()==1)//This is the case where you only have one term in the polynomial.
            {
                if(this->getHead()->getCoefficient()>0)//This checks to see if you have a positive number as you cannot take the square root of a negative number.
                {
                    bool isRoot=false;
                    bool isNotRoot=false;
                    long long base=0;
                    long long base2=0;
                    while(isRoot==false&&isNotRoot==false)
                    {
                       base2=base;
                       for(long long exponent=0; exponent<2-1; exponent++)
                       {
                            base2*=base;
                       }

                       if(base2==this->getHead()->getCoefficient())
                       {
                           isRoot=true;
                       }

                       else if(base==this->getHead()->getCoefficient())
                       {
                           isNotRoot=true;
                       }

                       else
                       {
                           base++;
                       }
                    }

                    if(isRoot==true)
                    {
                        this->getHead()->setCoefficient(base);
                        this->getHead()->setExponent(this->getHead()->getExponent()/2);
                    }

                    else
                    {
                        std::cout<<"The polynomial "<<*this<<" does not have a square root.\n"<<std::endl;
                    }
                }

                else
                {
                    std::cout<<"You cannot take the square root of "<<*this<<" as taking the square root of a single-term polynomial with a negative coefficient is undefined.\n"<<std::endl;
                }
            }

            else//This is the case where you have more than one term in the polynomial.
            {
                bool isFirstTermNegative=false;
                bool isLastTermNegative=false;
                if(this->getHead()->getCoefficient()<0)
                {
                    isFirstTermNegative=true;
                }

                if(isFirstTermNegative==false)
                {
                    Term* rootTerm=this->getHead();
                    while(rootTerm->getNext()!=NULL)
                    {
                        rootTerm=rootTerm->getNext();
                    }

                    if(rootTerm->getCoefficient()<0)
                    {
                        isLastTermNegative=true;
                    }

                    rootTerm=NULL;
                }

                if(isFirstTermNegative==true||isLastTermNegative==true)
                {
                    std::cout<<"The polynomial "<<*this<<" does not have a square root because the coefficient of either its first or last term is negative and the square root of a polynomial containing a first or last term with a negative coefficient is undefined.\n"<<std::endl;
                }

                else
                {
                    bool isRoot=false;
                    PolynomialStack* rootPStack=new PolynomialStack();
                    PolynomialStack* rootPStack2=new PolynomialStack();
                    PolynomialStack* rootPStack3=new PolynomialStack();
                    PolynomialStack* rootPStack4=new PolynomialStack();

                    Term* rootTerm=this->getHead();
                    while(rootTerm!=NULL)
                    {
                        if(rootTerm==this->getHead())
                        {
                            Term* rootTerm2=new Term(rootTerm->getCoefficient(), rootTerm->getVariable(), rootTerm->getExponent(), NULL);
                            Polynomial* P=new Polynomial();
                            P->push(rootTerm2);
                            rootPStack->push(P);

                            delete P;
                            P=NULL;

                            rootTerm=rootTerm->getNext();
                        }

                        else
                        {
                            Polynomial* P=new Polynomial();
                            for(long long rootTermCount=0; rootTermCount<2&&rootTerm!=NULL; rootTermCount++)
                            {
                                Term* rootTerm2=new Term(rootTerm->getCoefficient(), rootTerm->getVariable(), rootTerm->getExponent(), NULL);
                                P->push(rootTerm2);
                                rootTerm=rootTerm->getNext();
                            }

                            rootPStack->push(P);

                            delete P;
                            P=NULL;
                        }
                    }

                    long long rootPStackSize=0;
                    PolynomialStackNode* rootPStackNode=rootPStack->getTop();
                    while(rootPStackNode!=NULL)
                    {
                        rootPStackSize++;
                        rootPStackNode=rootPStackNode->getNext();
                    }

                    for(long long rootPStackSizeCount=0; rootPStackSizeCount<rootPStackSize; rootPStackSizeCount++)
                    {
                        while(rootPStack->getTop()->getNext()!=NULL)
                        {
                            rootPStack2->push(rootPStack->getTop()->getP());
                            rootPStack->pop();
                        }

                        if(rootPStackSizeCount==0)
                        {
                            Term* rootTerm=new Term(rootPStack->getTop()->getP()->getHead()->getCoefficient(), rootPStack->getTop()->getP()->getHead()->getVariable(), rootPStack->getTop()->getP()->getHead()->getExponent(), NULL);
                            Polynomial* P=new Polynomial();
                            P->push(rootTerm);
                            P->squareRoot();
                            rootPStack3->push(P);
                            rootPStack4->push(P);

                            delete P;
                            P=NULL;
                        }

                        else
                        {
                            Polynomial* P=new Polynomial(*rootPStack3->getTop()->getP());
                            if(P->getNumberOfTerms()==1)
                            {
                                P->exponent(2-1);
                                P->getHead()->setCoefficient(P->getHead()->getCoefficient()*2);
                            }

                            else
                            {
                                Term* rootTerm=P->getHead();
                                while(rootTerm->getNext()!=NULL)
                                {
                                    rootTerm=rootTerm->getNext();
                                }

                                Term* rootTerm2=new Term(rootTerm->getCoefficient(), rootTerm->getVariable(), rootTerm->getExponent(), NULL);
                                P->removeTerm(rootTerm2->getCoefficient(), rootTerm2->getVariable(), rootTerm2->getExponent());
                                Polynomial* P2=new Polynomial();
                                P2->push(rootTerm2);
                                P2->exponent(2-1);
                                P2->getHead()->setCoefficient(P2->getHead()->getCoefficient()*2);
                                *P=*P+*P2;

                                rootTerm=NULL;

                                delete P2;
                                P2=NULL;
                            }

                            Term* rootTerm=new Term(P->getHead()->getCoefficient(), P->getHead()->getVariable(), P->getHead()->getExponent(), NULL);
                            Polynomial* P2=new Polynomial();
                            P2->push(rootTerm);

                            Polynomial* P3=new Polynomial();
                            if(rootPStack->getTop()->getP()->getHead()!=NULL)
                            {
                                Term* rootTerm=new Term(rootPStack->getTop()->getP()->getHead()->getCoefficient(), rootPStack->getTop()->getP()->getHead()->getVariable(), rootPStack->getTop()->getP()->getHead()->getExponent(), NULL);
                                P3->push(rootTerm);
                            }

                            Polynomial* P4=new Polynomial();
                            *P4=*P3/(*P2);
                            *P=*P+*P4;
                            *P3=*rootPStack->getTop()->getP();
                            *P3=*P3-*P**P4;

                            if(rootPStack2->getTop()!=NULL)
                            {
                                *rootPStack2->getTop()->getP()=*rootPStack2->getTop()->getP()+*P3;
                            }

                            else
                            {
                                if(P3->getHead()==NULL)
                                {
                                    isRoot=true;
                                }
                            }

                            rootPStack3->push(P);
                            rootPStack4->push(P4);

                            delete P;
                            P=NULL;

                            delete P2;
                            P2=NULL;

                            delete P3;
                            P3=NULL;

                            delete P4;
                            P4=NULL;
                        }

                        rootPStack->pop();
                        while(rootPStack2->getTop()!=NULL)
                        {
                            rootPStack->push(rootPStack2->getTop()->getP());
                            rootPStack2->pop();
                        }
                    }

                    if(isRoot==true)
                    {
                        this->setNumberOfTerms(0);

                        while(this->getHead()!=NULL)
                        {
                            Term* clearTerm=this->getHead();
                            this->setHead(this->getHead()->getNext());
                            delete clearTerm;
                            clearTerm=NULL;
                        }

                        while(rootPStack4->getTop()!=NULL)
                        {
                            *this=*this+*rootPStack4->getTop()->getP();
                            rootPStack4->pop();
                        }
                    }

                    else
                    {
                        std::cout<<"The polynomial "<<*this<<" does not have a square root. It will remain unchanged.\n"<<std::endl;
                    }

                    delete rootPStack;
                    rootPStack=NULL;

                    delete rootPStack2;
                    rootPStack2=NULL;

                    delete rootPStack3;
                    rootPStack3=NULL;

                    delete rootPStack4;
                    rootPStack4=NULL;
                }
            }
        }
    }
}

void Polynomial::factorial()
{
   if(this->getHead()==NULL)
   {
       std::srand(time(NULL));
       char variable='a'+std::rand()%26;
       this->setHead(new Term(1, variable, 0, NULL));
   }

   else
   {
       bool isCoefficientOne=false;
       bool isCoefficientNegative=false;
       Polynomial* factorial=new Polynomial(*this);
       Polynomial* factorial2=new Polynomial(*this);
       while(isCoefficientOne==false&&isCoefficientNegative==false)
       {
           Term* factorialTerm=factorial2->getHead();
           while(factorialTerm!=NULL)
           {
               if(factorialTerm->getCoefficient()==1)
               {
                   isCoefficientOne=true;
                   factorialTerm=NULL;
               }

               else if(factorialTerm->getCoefficient()<0)
               {
                   isCoefficientNegative=true;
                   factorialTerm=NULL;
               }

               else
               {
                   factorialTerm=factorialTerm->getNext();
               }
           }

           if(isCoefficientOne==false&&isCoefficientNegative==false)
           {
               factorialTerm=factorial2->getHead();
               while(factorialTerm!=NULL)
               {
                   if(factorialTerm->getExponent()==0)
                   {
                       factorialTerm->setCoefficient(factorialTerm->getCoefficient()-1);
                   }

                   else
                   {
                       factorialTerm->setCoefficient(factorialTerm->getCoefficient()-1);
                       factorialTerm->setExponent(factorialTerm->getExponent()-1);
                   }

                   factorialTerm=factorialTerm->getNext();
               }

               *factorial=*factorial**factorial2;
           }
       }

       *this=*factorial;

       delete factorial;
       factorial=NULL;

       delete factorial2;
       factorial2=NULL;

       if(isCoefficientNegative==true)
       {
           std::cout<<"The factorial of the polynomial could not be taken because the polynomial contains a negative term coefficient and factorialization for negative coefficients is undefined.\n"<<std::endl;
       }
   }
}

void Polynomial::evaluate(long double evaluateNumber)
{
    long double evaluateNumber2=0;
    Term* evaluateTerm=this->getHead();
    while(evaluateTerm!=NULL)
    {
        if(evaluateTerm->getExponent()<0)
        {
            evaluateNumber2+=evaluateTerm->getCoefficient()/std::pow(evaluateNumber, evaluateTerm->getExponent()*-1);
        }

        else
        {
            evaluateNumber2+=evaluateTerm->getCoefficient()*std::pow(evaluateNumber, evaluateTerm->getExponent());
        }

        evaluateTerm=evaluateTerm->getNext();
    }

    std::cout<<"The result of the evaluation with the argument "<<evaluateNumber<<" is "<<evaluateNumber2<<".\n"<<std::endl;
}

void Polynomial::zero(long double zero)
{
    if(this->getHead()==NULL)
    {
        std::cout<<"The polynomial cannot have any zeros as it is an empty polynomial.\n"<<std::endl;
    }

    else
    {
        NumberStack* syntheticDivisionStack=new NumberStack();
        Term* zeroTerm=this->getHead();
        Term* zeroTerm2=this->getHead();
        while(zeroTerm2!=NULL)
        {
            if(zeroTerm2==this->getHead())
            {
                long double leadingCoefficient=zeroTerm2->getCoefficient();
                syntheticDivisionStack->push(leadingCoefficient);
                zeroTerm=zeroTerm2;
                zeroTerm2=zeroTerm2->getNext();
            }

            else if(abs(zeroTerm->getExponent())>abs(zeroTerm2->getExponent())+1)
            {
                for(long long fillingTerms=0; fillingTerms<abs(zeroTerm->getExponent())-abs(zeroTerm2->getExponent())-1; fillingTerms++)
                {
                    syntheticDivisionStack->push(0+zero*syntheticDivisionStack->getTop()->getNumberData());
                }

                zeroTerm=zeroTerm2;
            }

            else
            {
                long double termCoefficient=zeroTerm2->getCoefficient();
                syntheticDivisionStack->push(termCoefficient+zero*syntheticDivisionStack->getTop()->getNumberData());
                zeroTerm=zeroTerm2;
                zeroTerm2=zeroTerm2->getNext();
            }
        }

        bool isNegativeExponent=false;
        if(this->getHead()->getNext()==NULL)
        {
            if(this->getHead()->getExponent()<0)
            {
                isNegativeExponent=true;
            }
        }

        zeroTerm=this->getHead();
        while(zeroTerm->getNext()!=NULL)
        {
            if(zeroTerm->getExponent()<0)
            {
                if(isNegativeExponent==false)
                {
                    isNegativeExponent=true;
                }

                zeroTerm=zeroTerm->getNext();
            }

            else
            {
                zeroTerm=zeroTerm->getNext();
            }
        }

        if(zeroTerm->getExponent()<0&&zeroTerm!=this->getHead())
        {
            if(isNegativeExponent==false)
            {
                isNegativeExponent=true;
            }
        }

        if(zeroTerm->getExponent()>0&&isNegativeExponent==false)//This is the case where you have a polynomial where the last term is not a constant.
        {
            if(zero==0)
            {
                std::cout<<"The number "<<zero<<" is a zero of the polynomial.\n"<<std::endl;
            }

            else
            {
                long long zeroResult=syntheticDivisionStack->getTop()->getNumberData();
                if(zeroResult==0)
                {
                    std::cout<<"The number "<<zero<<" is a zero of the polynomial.\n"<<std::endl;
                }

                else
                {
                    std::cout<<"The number "<<zero<<" is not a zero of the polynomial.\n"<<std::endl;
                }
            }
        }

        else
        {
            if(zero==0&&isNegativeExponent==true)
            {
                std::cout<<"The number "<<zero<<" cannot be a zero for the polynomial because due to the presence of a negative exponent in the polynomial, using "<<zero<<" as an argument for evaluation would lead to an undefined value.\n"<<std::endl;
            }

            else
            {
                long long zeroResult=syntheticDivisionStack->getTop()->getNumberData();
                if(zeroResult==0)
                {
                    std::cout<<"The number "<<zero<<" is a zero of the polynomial.\n"<<std::endl;
                }

                else
                {
                    std::cout<<"The number "<<zero<<" is not a zero of the polynomial.\n"<<std::endl;
                }
            }
        }

        zeroTerm=NULL;

        delete syntheticDivisionStack;
        syntheticDivisionStack=NULL;
    }
}

void Polynomial::allRationalZeros()
{
    if(this->getHead()==NULL)
    {
        std::cout<<"The polynomial cannot have any rational zeros as it is an empty polynomial.\n"<<std::endl;
    }

    else
    {
        NumberStack* leadingTermFactorsStack=new NumberStack();
        NumberStack* lastTermFactorsStack=new NumberStack();
        long long leadingTermCoefficient=abs(this->getHead()->getCoefficient());
        bool isNegativeExponent=false;
        Term* lastTerm=this->getHead();
        while(lastTerm->getNext()!=NULL)
        {
            if(lastTerm->getExponent()<0)
            {
                if(isNegativeExponent==false)
                {
                    isNegativeExponent=true;
                }
            }

            lastTerm=lastTerm->getNext();
        }

        if(lastTerm->getExponent()<0)//This is to check the last term in the polynomial as the loop above will not get to check it.
        {
            if(isNegativeExponent==false)
            {
                isNegativeExponent=true;
            }
        }

        long long lastTermCoefficient=abs(lastTerm->getCoefficient());
        for(long long leadingTermFactor=1; leadingTermFactor<=leadingTermCoefficient; leadingTermFactor++)
        {
            if(leadingTermCoefficient%leadingTermFactor==0)
            {
                leadingTermFactorsStack->push(leadingTermFactor);
            }
        }

        for(long long lastTermFactor=1; lastTermFactor<=lastTermCoefficient; lastTermFactor++)
        {
            if(lastTermCoefficient%lastTermFactor==0)
            {
                lastTermFactorsStack->push(lastTermFactor);
            }
        }

        NumberStack* rationalZerosStack=new NumberStack();
        NumberStackNode* lastTermFactorsStackPtr=lastTermFactorsStack->getTop();
        while(lastTermFactorsStackPtr!=NULL)
        {
            NumberStackNode* firstTermFactorsStackPtr=leadingTermFactorsStack->getTop();
            while(firstTermFactorsStackPtr!=NULL)
            {
                rationalZerosStack->push(lastTermFactorsStackPtr->getNumberData()/firstTermFactorsStackPtr->getNumberData());
                rationalZerosStack->push(rationalZerosStack->getTop()->getNumberData()*-1);
                firstTermFactorsStackPtr=firstTermFactorsStackPtr->getNext();
            }

            lastTermFactorsStackPtr=lastTermFactorsStackPtr->getNext();
        }

        if(lastTerm->getExponent()>0&&isNegativeExponent==false)
        {
            rationalZerosStack->push(0);
        }

        while(rationalZerosStack->getTop()!=NULL)
        {
            this->zero(rationalZerosStack->getTop()->getNumberData());
            rationalZerosStack->pop();
        }

        lastTerm=NULL;

        delete leadingTermFactorsStack;
        leadingTermFactorsStack=NULL;

        delete lastTermFactorsStack;
        lastTermFactorsStack=NULL;

        delete rationalZerosStack;
        rationalZerosStack=NULL;
    }
}

void Polynomial::removeTerm(long long coefficient, char variable, long long exponent)
{
    if(this->getHead()==NULL)
    {
        std::cout<<"There are no terms to remove from the polynomial because the polynomial is empty.\n"<<std::endl;
    }

    else
    {
        bool isTermRemoved=false;
        Term* removeTerm=this->getHead();
        Term* removeTerm2=this->getHead();
        while(removeTerm2!=NULL)
        {
            if(removeTerm2->getCoefficient()==coefficient&&removeTerm2->getVariable()==variable&&removeTerm2->getExponent()==exponent)
            {
                if(removeTerm2->getNext()==NULL)
                {
                    if(removeTerm2==this->getHead())
                    {
                        delete removeTerm2;
                        this->setHead(NULL);
                        removeTerm=NULL;
                        removeTerm2=NULL;
                    }

                    else
                    {
                        removeTerm->setNext(NULL);
                        delete removeTerm2;
                        removeTerm=NULL;
                        removeTerm2=NULL;
                    }
                }

                else
                {
                    if(removeTerm2==this->getHead())
                    {
                        this->setHead(this->getHead()->getNext());
                        delete removeTerm2;
                        removeTerm=NULL;
                        removeTerm2=NULL;
                    }

                    else
                    {
                        removeTerm->setNext(removeTerm2->getNext());
                        delete removeTerm2;
                        removeTerm=NULL;
                        removeTerm2=NULL;
                    }
                }

                isTermRemoved=true;
                this->setNumberOfTerms(this->getNumberOfTerms()-1);
            }

            else
            {
                removeTerm=removeTerm2;
                removeTerm2=removeTerm2->getNext();
            }
        }

        if(isTermRemoved==true)
        {
            std::cout<<"The term "<<coefficient<<variable<<exponent<<" has successfully been removed from the polynomial.\n"<<std::endl;
        }

        else
        {
            std::cout<<"The term "<<coefficient<<variable<<exponent<<" was not able to be removed from the polynomial because it did not exist in the polynomial prior to being referenced for removal.\n"<<std::endl;
        }
    }
}

void Polynomial::inputFromFile(std::string fileInput)
{
    std::fstream inputFileStream(fileInput.c_str());
    if(inputFileStream.is_open())
    {
        if(this->getHead()!=NULL)
        {
            std::cout<<"The file "<<fileInput<<" was able to be opened to upload a polynomial from it. However, you are about to overwrite the current polynomial with the potential polynomial from the file.\n"<<std::endl;
            std::cout<<"To give you the option to proceed with overwriting the current polynomial or not, a menu will now be displayed that will allow you to pick your choice of whether you will want to overwrite the current polynomial or not.\n"<<std::endl;

            std::cout<<"1. Overwrite the current polynomial."<<std::endl;
            std::cout<<"2. Do not overwrite the current polynomial.\n"<<std::endl;

            std::cout<<"Please enter your choice based on the number associated with its description.\n"<<std::endl;

            std::string overwriteChoice=std::string();
            int overwriteChoice2=0;
            do
            {
                std::getline(std::cin, overwriteChoice);
                std::cout<<std::endl;
                std::stringstream overwriteChoiceSS(overwriteChoice);
                overwriteChoiceSS>>overwriteChoice2;
                switch(overwriteChoice2)
                {
                    case 1:
                    {
                        std::cout<<"Now the current polynomial will be overwritten with the polynomial from "<<fileInput<<".\n"<<std::endl;

                        this->setNumberOfTerms(0);

                        while(this->getHead()!=NULL)
                        {
                            Term* clearTerm=this->getHead();
                            this->setHead(this->getHead()->getNext());
                            delete clearTerm;
                            clearTerm=NULL;
                        }

                        std::string inputFileInsert=std::string();
                        while(inputFileStream>>inputFileInsert)
                        {
                            std::stringstream inputFileInsertSS(inputFileInsert);
                            inputFileInsertSS>>*this;
                        }

                        std::cout<<"The polynomial from the file "<<fileInput<<" has successfully been loaded into the current polynomial.\n"<<std::endl;

                        break;
                    }

                    case 2:
                    {
                        std::cout<<"The current polynomial will not be overwritten. If you wish to overwrite the polynomial at a later time, you may do so by choosing to input a polynomial from a file again by choosing the appropriate menu choice.\n"<<std::endl;

                        break;
                    }

                    default:
                    {
                        break;
                    }
                }

                if(overwriteChoice2!=1&&overwriteChoice2!=2)
                {
                    std::cout<<"Now a menu will be re-created showing the possible choices of choosing whether to overwrite the current polynomial or not for reminding purposes.\n"<<std::endl;
                    std::cout<<"1. Overwrite the current polynomial."<<std::endl;
                    std::cout<<"2. Do not overwrite the current polynomial.\n"<<std::endl;
                    std::cout<<"Please enter your next choice by entering the number associated with its description.\n"<<std::endl;
                }

                else
                {
                    break;
                }
            }

            while(overwriteChoice2!=1&&overwriteChoice2!=2);
        }

        else
        {
            std::cout<<"Now the polynomial from "<<fileInput<<" will be loaded into the current polynomial.\n"<<std::endl;

            std::string inputFileInsert=std::string();
            while(inputFileStream>>inputFileInsert)
            {
                std::stringstream inputFileInsertSS(inputFileInsert);
                inputFileInsertSS>>*this;
            }

            std::cout<<"The polynomial from the file "<<fileInput<<" has successfully been loaded into the current polynomial.\n"<<std::endl;
        }
    }

    else
    {
        std::cout<<"The file "<<fileInput<<" could not be opened to load a polynomial from it. If you wish to attempt to load a polynomial from a file again you may do so by choosing the appropriate menu choice.\n"<<std::endl;
    }

    inputFileStream.close();
}

void Polynomial::ouputToFile(std::string fileOutput)
{
    std::fstream outputFileStream(fileOutput.c_str(), std::ios::in);
    if(outputFileStream.is_open())
    {
        if(this->getHead()!=NULL)
        {
            std::cout<<"The file "<<fileOutput<<" was able to be opened to store a polynomial to it. However, you are about to overwrite any data that it contains with the current polynomial.\n"<<std::endl;
            std::cout<<"To give you the option to proceed with overwriting the file with the current polynomial or not, a menu will now be displayed that will allow you to pick your choice of whether you will want to overwrite the file with the current polynomial or not.\n"<<std::endl;

            std::cout<<"1. Overwrite the file with the current polynomial."<<std::endl;
            std::cout<<"2. Do not overwrite the file with the current polynomial.\n"<<std::endl;

            std::cout<<"Please enter your choice based on the number associated with its description.\n"<<std::endl;

            std::string overwriteFileChoice=std::string();
            int overwriteFileChoice2=0;
            do
            {
                std::getline(std::cin, overwriteFileChoice);
                std::cout<<std::endl;
                std::stringstream overwriteFileChoiceSS(overwriteFileChoice);
                overwriteFileChoiceSS>>overwriteFileChoice2;
                switch(overwriteFileChoice2)
                {
                    case 1:
                    {
                        std::cout<<"Now the file "<<fileOutput<<" will be overwritten with the current polynomial.\n"<<std::endl;

                        outputFileStream.close();
                        outputFileStream.open(fileOutput.c_str(), std::ios::out|std::ios::trunc);
                        if(outputFileStream.is_open())
                        {
                            outputFileStream<<*this;
                            std::cout<<"The current polynomial was successfully stored to "<<fileOutput<<".\n"<<std::endl;
                        }

                        else
                        {
                            std::cout<<"The file could not be overwritten to store the current polynomial to it. If you wish to try to store the polynomial to a file again you may do so by choosing the appropriate menu choice.\n"<<std::endl;
                        }

                        break;
                    }

                    case 2:
                    {
                        std::cout<<"No polynomial data will be stored to "<<fileOutput<<" if you wish to store a polynomial to a file at a later time, you may do so by choosing the appropriate menu choice.\n"<<std::endl;

                        break;
                    }

                    default:
                    {
                        break;
                    }
                }

                if(overwriteFileChoice2!=1&&overwriteFileChoice2!=2)
                {
                    std::cout<<"Now a menu will be re-created showing the possible choices of choosing whether to overwrite the file with the current polynomial or not for reminding purposes.\n"<<std::endl;
                    std::cout<<"1. Overwrite the file with the current polynomial."<<std::endl;
                    std::cout<<"2. Do not overwrite the file with the current polynomial.\n"<<std::endl;
                    std::cout<<"Please enter your next choice by entering the number associated with its description.\n"<<std::endl;
                }

                else
                {
                    break;
                }
            }

            while(overwriteFileChoice2!=1&&overwriteFileChoice2!=2);
        }

        else
        {
            std::cout<<"The current polynomial is empty. Thus no polynomial data could be stored to "<<fileOutput<<".\n"<<std::endl;
        }
    }

    else
    {
        if(this->getHead()!=NULL)
        {
            std::cout<<"Now the file "<<fileOutput<<" will be overwritten with the current polynomial.\n"<<std::endl;

            outputFileStream.close();
            outputFileStream.open(fileOutput.c_str(), std::ios::out|std::ios::trunc);
            if(outputFileStream.is_open())
            {
                outputFileStream<<*this;
                std::cout<<"The current polynomial was successfully stored to "<<fileOutput<<".\n"<<std::endl;
            }

            else
            {
                std::cout<<"The file could not be overwritten to store the current polynomial to it. If you wish to try to store the polynomial to a file again you may do so by choosing the appropriate menu choice.\n"<<std::endl;
            }
        }

        else
        {
            std::cout<<"The current polynomial is empty. Thus no polynomial data could be stored to "<<fileOutput<<".\n"<<std::endl;
        }
    }

    outputFileStream.close();
}
