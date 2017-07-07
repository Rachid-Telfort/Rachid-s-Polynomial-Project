#include"Polynomial.h"

int main(int argc, char* argv[])
{
    std::cout<<"Welcome to the polynomial manipulator.\n"<<std::endl;
    std::cout<<"Now a menu will be created showing the possible types of polynomials you can initialize for the program.\n"<<std::endl;
    Polynomial* P=NULL;

    std::cout<<"1. Initialize an empty polynomial for use in the program."<<std::endl;
    std::cout<<"2. Initialize an arbitrary polynomial with a selected number of terms for use in the program."<<std::endl;
    std::cout<<"3. Initialize a polynomial from a file for use in the program."<<std::endl;
    std::cout<<"4. Quit the polynomial manipulator program.\n"<<std::endl;
    std::cout<<"Now you will enter your desired choice by entering the number associated with its description.\n"<<std::endl;

    std::string polynomialChoice=std::string();
    int polynomialChoice2=0;
    do
    {
        std::getline(std::cin, polynomialChoice);
        std::cout<<std::endl;
        std::stringstream polynomialChoiceSS(polynomialChoice);
        polynomialChoiceSS>>polynomialChoice2;
        switch(polynomialChoice2)
        {
            case 1:
            {
                std::cout<<"Now an empty polynomial will be created for you to manipulate.\n"<<std::endl;
                P=new Polynomial();

                break;
            }

            case 2:
            {
                std::cout<<"You will now choose how many terms you will want in an arbitrary polynomial.\n"<<std::endl;
                std::string numberOfTermsChoice=std::string();
                std::getline(std::cin, numberOfTermsChoice);
                std::cout<<std::endl;
                std::stringstream numberOfTermsChoiceSS(numberOfTermsChoice);
                long long numberOfTerms=0;
                numberOfTermsChoiceSS>>numberOfTerms;
                std::cout<<"Now an arbitrary polynomial will be made for you with your selected number of terms.\n"<<std::endl;
                P=new Polynomial(numberOfTerms);

                break;
            }

            case 3:
            {
               std::cout<<"Now you will enter the file name from which you want to initialize a polynomial from.\n"<<std::endl;
               std::string pFileName=std::string();
               std::getline(std::cin, pFileName);
               std::cout<<std::endl;
               std::cout<<"Now a polynomial will be attempted to be initialized from your input file.\n"<<std::endl;
               P=new Polynomial(pFileName);

               break;
            }

            case 4:
            {
                return 0;

                break;
            }

            default:
            {
                break;
            }
        }

        if(polynomialChoice2!=1&&polynomialChoice2!=2&&polynomialChoice2!=3)
        {
            std::cout<<"Now a menu will be re-created showing the possible choices of initializing a polynomial for use in the polynomial manipulator program for reminding purposes.\n"<<std::endl;
            std::cout<<"1. Initialize an empty polynomial for use in the program."<<std::endl;
            std::cout<<"2. Initialize an arbitrary polynomial with a selected number of terms for use in the program."<<std::endl;
            std::cout<<"3. Initialize a polynomial from a file for use in the program."<<std::endl;
            std::cout<<"4. Quit the polynomial manipulator program.\n"<<std::endl;
            std::cout<<"Please enter your next choice by entering the number associated with its description.\n"<<std::endl;
        }

        else
        {
            break;
        }
    }

    while(polynomialChoice2!=1&&polynomialChoice2!=2&&polynomialChoice2!=3);

    std::cout<<"Now that your choice of working polynomial has been created, another menu will be created showing the possible operations that can be done on the working polynomial.\n"<<std::endl;
    std::cout<<"1. Insert a term/a number of terms into the working polynomial."<<std::endl;
    std::cout<<"2. Print out the current terms in the working polynomial."<<std::endl;
    std::cout<<"3. Add another polynomial to the working polynomial."<<std::endl;
    std::cout<<"4. Subtract another polynomial from the working polynomial."<<std::endl;
    std::cout<<"5. Multiply the working polynomial by another polynomial."<<std::endl;
    std::cout<<"6. Divide the working polynomial by another polynomial."<<std::endl;
    std::cout<<"7. Modulus the working polynomial by another polynomial."<<std::endl;
    std::cout<<"8. Exponentiate the working polynomial by a certain exponent."<<std::endl;
    std::cout<<"9. Take the square root of the working polynomial."<<std::endl;
    std::cout<<"10. Factorialize the working polynomial."<<std::endl;
    std::cout<<"11. Evaluate the working polynomial by a certain number/certain numbers."<<std::endl;
    std::cout<<"12. Input a number/set of numbers to see if it/they is/are a zero/zeros of the working polynomial or not."<<std::endl;
    std::cout<<"13. Retrieve all the possible rational zeros of the working polynomial."<<std::endl;
    std::cout<<"14. Remove a term/a number of terms from the working polynomial."<<std::endl;
    std::cout<<"15. View the current number of terms in the working polynomial."<<std::endl;
    std::cout<<"16. Clear the working polynomial for the insertion of a new set/new sets of terms."<<std::endl;
    std::cout<<"17. Load a polynomial from a file to overwrite the working polynomial with."<<std::endl;
    std::cout<<"18. Store the working polynomial to a file for future use."<<std::endl;
    std::cout<<"19. If running the program on command line and the program has arguments, use the arguments to perform a set of operations on the polynomial manipulator program."<<std::endl;
    std::cout<<"20. Quit the polynomial manipulator program.\n"<<std::endl;

    std::cout<<"Now you will choose the operation you want to do on the working polynomial by entering the number associated with its description.\n"<<std::endl;
    std::string menuChoice=std::string();
    std::getline(std::cin, menuChoice);
    std::cout<<std::endl;
    std::stringstream menuChoiceSS(menuChoice);
    int menuChoice2=0;
    menuChoiceSS>>menuChoice2;
    while(menuChoice2!=20)
    {
        switch(menuChoice2)
        {
            case 1:
            {
                std::cout<<"Now you will type the term/number of terms that you want to insert into the working polynomial.\n"<<std::endl;
                std::string termsInsert=std::string();
                std::getline(std::cin, termsInsert);
                std::cout<<std::endl;

                if(termsInsert==std::string())
                {
                    std::cout<<"It appears that no term(s) were input to insert into the working polynomial.\n"<<std::endl;
                }

                else
                {
                    std::cout<<"Now your typed terms will be inserted into the working polynomial.\n"<<std::endl;

                    std::stringstream termsInsertSS(termsInsert);
                    while(termsInsertSS>>termsInsert)
                    {
                        std::stringstream termsInsertSS2(termsInsert);
                        termsInsertSS2>>*P;
                    }
                }

                break;
            }

            case 2:
            {
                if(P->getHead()==NULL)
                {
                    std::cout<<"There are currently no terms in the working polynomial to print. Please insert some terms in the working polynomial in order to print them later.\n"<<std::endl;
                }

                else
                {
                    std::cout<<"Now all the current terms in the working polynomial will be printed.\n"<<std::endl;
                    std::cout<<*P;
                    std::cout<<std::endl;
                }

                break;
            }

            case 3:
            {
                std::cout<<"Now a second polynomial will be made for you to add to the working polynomial.\n"<<std::endl;
                Polynomial* P2=new Polynomial();

                std::cout<<"Now you will type the term/number of terms that you want to insert into the second polynomial.\n"<<std::endl;
                std::string termsInsert=std::string();
                std::getline(std::cin, termsInsert);
                std::cout<<std::endl;
                std::stringstream termsInsertSS(termsInsert);
                while(termsInsertSS>>termsInsert)
                {
                    std::stringstream termsInsertSS2(termsInsert);
                    termsInsertSS2>>*P2;
                }

                if(P2->getHead()==NULL)
                {
                    std::cout<<"It seems that no terms were inserted into the second polynomial for addition. Thus there are no terms in the second polynomial to print.\n"<<std::endl;
                }

                else
                {
                    if(P->getHead()!=NULL)
                    {
                        if(P->getHead()->getVariable()!=P2->getHead()->getVariable())
                        {
                            Term* variableTerm=P2->getHead();
                            while(variableTerm!=NULL)
                            {
                                variableTerm->setVariable(P->getHead()->getVariable());
                                variableTerm=variableTerm->getNext();
                            }
                        }
                    }

                    std::cout<<"Now all the terms in the second polynomial will be printed for you to see which terms that are about to be added to the working polynomial.\n"<<std::endl;
                    std::cout<<*P2;
                    std::cout<<std::endl;
                }

                std::cout<<"Now the second polynomial will be added to the working polynomial.\n"<<std::endl;
                *P=*P+*P2;

                if(P->getHead()==NULL)
                {
                    std::cout<<"The addition resulted in the working polynomial having zero value. Thus there are no terms in the working polynomial to print."<<std::endl;
                }

                else
                {
                    std::cout<<"The sum which is now stored in the working polynomial will be displayed.\n"<<std::endl;
                    std::cout<<*P;
                    std::cout<<std::endl;
                }

                delete P2;
                P2=NULL;

                break;
            }

            case 4:
            {
                std::cout<<"Now a second polynomial will be made for you to subtract from the working polynomial.\n"<<std::endl;
                Polynomial* P2=new Polynomial();

                std::cout<<"Now you will type the term/number of terms that you want to insert into the second polynomial.\n"<<std::endl;
                std::string termsInsert=std::string();
                std::getline(std::cin, termsInsert);
                std::cout<<std::endl;
                std::stringstream termsInsertSS(termsInsert);
                while(termsInsertSS>>termsInsert)
                {
                    std::stringstream termsInsertSS2(termsInsert);
                    termsInsertSS2>>*P2;
                }

                if(P2->getHead()==NULL)
                {
                    std::cout<<"It seems that no terms were added to the second polynomial for subtraction. Thus there are no terms in the second polynomial to print.\n"<<std::endl;
                }

                else
                {
                    if(P->getHead()!=NULL)
                    {
                        if(P->getHead()->getVariable()!=P2->getHead()->getVariable())
                        {
                            Term* variableTerm=P2->getHead();
                            while(variableTerm!=NULL)
                            {
                                variableTerm->setVariable(P->getHead()->getVariable());
                                variableTerm=variableTerm->getNext();
                            }
                        }
                    }

                    std::cout<<"Now all the terms in the second polynomial will be printed for you to see which terms that are about to be subtracted from the working polynomial.\n"<<std::endl;
                    std::cout<<*P2;
                    std::cout<<std::endl;
                }

                std::cout<<"Now the second polynomial will be subtracted from the working polynomial.\n"<<std::endl;
                *P=*P-*P2;

                if(P->getHead()==NULL)
                {
                    std::cout<<"The subtraction resulted in the working polynomial having zero value. Thus there are no terms in the working polynomial to print.\n"<<std::endl;
                }

                else
                {
                    std::cout<<"The difference which is now stored in the working polynomial will be displayed.\n"<<std::endl;
                    std::cout<<*P;
                    std::cout<<std::endl;
                }

                delete P2;
                P2=NULL;

                break;
            }

            case 5:
            {
                std::cout<<"Now a second polynomial will be made for you to multiply by the working polynomial.\n"<<std::endl;
                Polynomial* P2=new Polynomial();

                std::cout<<"Now you will type the term/number of terms that you want to insert into the second polynomial.\n"<<std::endl;
                std::string termsInsert=std::string();
                std::getline(std::cin, termsInsert);
                std::cout<<std::endl;
                std::stringstream termsInsertSS(termsInsert);
                while(termsInsertSS>>termsInsert)
                {
                    std::stringstream termsInsertSS2(termsInsert);
                    termsInsertSS2>>*P2;
                }

                if(P2->getHead()==NULL)
                {
                    std::cout<<"It seems that no terms were added to the second polynomial for multiplication. Thus there are no terms in the second polynomial to print.\n"<<std::endl;
                }

                else
                {
                    if(P->getHead()!=NULL)
                    {
                        if(P->getHead()->getVariable()!=P2->getHead()->getVariable())
                        {
                            Term* variableTerm=P2->getHead();
                            while(variableTerm!=NULL)
                            {
                                variableTerm->setVariable(P->getHead()->getVariable());
                                variableTerm=variableTerm->getNext();
                            }
                        }
                    }

                    std::cout<<"Now all the terms in the second polynomial will be printed for you to see which terms that are about to be multiplied by the working polynomial.\n"<<std::endl;
                    std::cout<<*P2;
                    std::cout<<std::endl;
                }

                std::cout<<"Now the second polynomial will be multiplied by the working polynomial.\n"<<std::endl;
                *P=*P**P2;

                if(P->getHead()==NULL)
                {
                    std::cout<<"The multiplication resulted in the working polynomial having zero value. Thus there are no terms in the working polynomial to print.\n"<<std::endl;
                }

                else
                {
                    std::cout<<"The product which is now stored in the working polynomial will be displayed.\n"<<std::endl;
                    std::cout<<*P;
                    std::cout<<std::endl;
                }

                delete P2;
                P2=NULL;

                break;
            }

            case 6:
            {
                std::cout<<"Now a second polynomial will be made for you to divide by the working polynomial.\n"<<std::endl;
                Polynomial* P2=new Polynomial();

                std::cout<<"Now you will type the term/number of terms that you want to insert into the second polynomial.\n"<<std::endl;
                std::string termsInsert=std::string();
                std::getline(std::cin, termsInsert);
                std::cout<<std::endl;
                std::stringstream termsInsertSS(termsInsert);
                while(termsInsertSS>>termsInsert)
                {
                    std::stringstream termsInsertSS2(termsInsert);
                    termsInsertSS2>>*P2;
                }

                if(P2->getHead()==NULL)
                {
                    std::cout<<"It seems that no terms were added to the second polynomial for division. Thus there are no terms in the second polynomial to print.\n"<<std::endl;
                }

                else
                {
                    if(P->getHead()!=NULL)
                    {
                        if(P->getHead()->getVariable()!=P2->getHead()->getVariable())
                        {
                            Term* variableTerm=P2->getHead();
                            while(variableTerm!=NULL)
                            {
                                variableTerm->setVariable(P->getHead()->getVariable());
                                variableTerm=variableTerm->getNext();
                            }
                        }
                    }

                    std::cout<<"Now all the terms in the second polynomial will be printed for you to see which terms that are about to be divided by the working polynomial.\n"<<std::endl;
                    std::cout<<*P2;
                    std::cout<<std::endl;
                }

                std::cout<<"Now the second polynomial will be divided by the working polynomial.\n"<<std::endl;
                *P=*P/(*P2);

                if(P->getHead()==NULL)
                {
                    std::cout<<"The division resulted in the working polynomial having zero or undefined value. Thus there are no terms in the working polynomial to print.\n"<<std::endl;
                }

                else
                {
                    std::cout<<"The quotient which is now stored in the working polynomial will be displayed.\n"<<std::endl;
                    std::cout<<*P;
                    std::cout<<std::endl;
                }

                delete P2;
                P2=NULL;

                break;
            }

            case 7:
            {
                std::cout<<"Now a second polynomial will be made for you to modulus by the working polynomial.\n"<<std::endl;
                Polynomial* P2=new Polynomial();

                std::cout<<"Now you will type the term/number of terms that you want to insert into the second polynomial.\n"<<std::endl;
                std::string termsInsert=std::string();
                std::getline(std::cin, termsInsert);
                std::cout<<std::endl;
                std::stringstream termsInsertSS(termsInsert);
                while(termsInsertSS>>termsInsert)
                {
                    std::stringstream termsInsertSS2(termsInsert);
                    termsInsertSS2>>*P2;
                }

                if(P2->getHead()==NULL)
                {
                    std::cout<<"It seems that no terms were added to the second polynomial for modulus. Thus there are no terms in the second polynomial to print.\n"<<std::endl;
                }

                else
                {
                    if(P->getHead()!=NULL)
                    {
                        if(P->getHead()->getVariable()!=P2->getHead()->getVariable())
                        {
                            Term* variableTerm=P2->getHead();
                            while(variableTerm!=NULL)
                            {
                                variableTerm->setVariable(P->getHead()->getVariable());
                                variableTerm=variableTerm->getNext();
                            }
                        }
                    }

                    std::cout<<"Now all the terms in the second polynomial will be printed for you to see which terms that are about to be modulus by the working polynomial.\n"<<std::endl;
                    std::cout<<*P2;
                    std::cout<<std::endl;
                }

                std::cout<<"Now the second polynomial will be modulus by the working polynomial.\n"<<std::endl;
                *P=*P%*P2;

                if(P->getHead()==NULL)
                {
                    std::cout<<"The modulus resulted in the working polynomial having zero or undefined value. Thus there are no terms in the working polynomial to print.\n"<<std::endl;
                }

                else
                {
                    std::cout<<"The modulus which is now stored in the working polynomial will be displayed.\n"<<std::endl;
                    std::cout<<*P;
                    std::cout<<std::endl;
                }

                delete P2;
                P2=NULL;

                break;
            }

            case 8:
            {
                std::cout<<"Now you will type the exponent you want to raise the working polynomial to.\n"<<std::endl;
                std::string exponentInsert=std::string();
                std::getline(std::cin, exponentInsert);
                std::cout<<std::endl;
                std::stringstream exponentInsertSS(exponentInsert);
                long long exponent=0;
                exponentInsertSS>>exponent;

                std::cout<<"Now the working polynomial will be raised to the "<<exponent<<" power.\n"<<std::endl;
                P->exponent(exponent);

                if(P->getHead()!=NULL)
                {
                    std::cout<<"The exponent result, which is now stored in the working polynomial will be displayed.\n"<<std::endl;
                    std::cout<<*P;
                    std::cout<<std::endl;
                }

                else
                {
                    std::cout<<"The exponentiation resulted in the working polynomial having zero value. Thus there are no terms in the working polynomial to print.\n"<<std::endl;
                }

                break;
            }

            case 9:
            {
                std::cout<<"Now the square root of the working polynomial will be attempted to be taken.\n"<<std::endl;
                P->squareRoot();

                if(P->getHead()!=NULL)
                {
                    std::cout<<"The square root result, which is now stored in the working polynomial will be displayed.\n"<<std::endl;
                    std::cout<<*P;
                    std::cout<<std::endl;
                }

                else
                {
                    std::cout<<"The square root resulted in the working polynomial having zero or undefined value. Thus there are no terms in the working polynomial to print.\n"<<std::endl;
                }

                break;
            }

            case 10:
            {
                std::cout<<"Now the working polynomial will be factorialized.\n"<<std::endl;
                P->factorial();

                std::cout<<"The factorial result, which is now stored in the working polynomial will be displayed.\n"<<std::endl;
                std::cout<<*P;
                std::cout<<std::endl;

                break;
            }

            case 11:
            {
                std::cout<<"Now you will type the number(s) you want to evaluate the working polynomial with.\n"<<std::endl;
                std::string numbersEvaluate=std::string();
                std::getline(std::cin, numbersEvaluate);
                std::cout<<std::endl;

                if(numbersEvaluate==std::string())
                {
                    std::cout<<"It appears that no numbers were input to evaluate the working polynomial with.\n"<<std::endl;
                }

                else
                {
                    std::cout<<"Now the working polynomial will be evaluated with the number(s) "<<numbersEvaluate<<".\n"<<std::endl;

                    long double evaluateNumber=0;
                    std::stringstream numbersEvaluateSS(numbersEvaluate);
                    while(numbersEvaluateSS>>numbersEvaluate)
                    {
                        std::stringstream numbersEvaluateSS2(numbersEvaluate);
                        numbersEvaluateSS2>>evaluateNumber;
                        P->evaluate(evaluateNumber);
                    }
                }

                break;
            }

            case 12:
            {
                std::cout<<"Now you will type the number(s) you want to test to see if it/they is/are a zero/zeros of the working polynomial or not.\n"<<std::endl;
                std::string zeros=std::string();
                std::getline(std::cin, zeros);
                std::cout<<std::endl;

                if(zeros==std::string())
                {
                    std::cout<<"It appears that there was/were no number(s) input to see if it/they is/are zeros of the working polynomial.\n"<<std::endl;
                }

                else
                {
                    std::cout<<"Now the polynomial manipulator program will check if "<<zeros<<" is/are a zero/zeros of the working polynomial.\n"<<std::endl;

                    long double zero=0;
                    std::stringstream zerosSS(zeros);
                    while(zerosSS>>zeros)
                    {
                        std::stringstream zerosSS2(zeros);
                        zerosSS2>>zero;
                        P->zero(zero);
                    }
                }

                break;
            }

            case 13:
            {
                std::cout<<"Now all the possible rational zeros will be attempted to be displayed for the working polynomial.\n"<<std::endl;
                P->allRationalZeros();

                break;
            }

            case 14:
            {
                std::cout<<"Now you will type the term/number of terms that you would like to remove from the working polynomial.\n"<<std::endl;
                std::string termsRemove=std::string();
                std::getline(std::cin, termsRemove);
                std::cout<<std::endl;

                if(termsRemove==std::string())
                {
                    std::cout<<"It appears that no term(s) were input to remove from the working polynomial.\n"<<std::endl;
                }

                else
                {
                    std::cout<<"Now your typed term(s) will be attempted to be removed from the working polynomial.\n"<<std::endl;

                    long long coefficient=0;
                    char variable='\0';
                    long long exponent=0;
                    std::stringstream termsRemoveSS(termsRemove);
                    while(termsRemoveSS>>termsRemove)
                    {
                        std::stringstream termsRemoveSS2(termsRemove);
                        termsRemoveSS2>>coefficient>>variable>>exponent;
                        P->removeTerm(coefficient, variable, exponent);
                    }
                }

                break;
            }

            case 15:
            {
                std::cout<<"Now the number of terms currently in the working polynomial will be displayed.\n"<<std::endl;
                std::cout<<"There is/are "<<P->getNumberOfTerms()<<" term(s) currently in the working polynomial.\n"<<std::endl;

                break;
            }

            case 16:
            {
                std::cout<<"Now your polynomial will be cleared for the insertion of a new set/new sets of terms.\n"<<std::endl;
                delete P;
                P=NULL;
                P=new Polynomial();

                break;
            }

            case 17:
            {
                std::cout<<"Now you will enter the file name from which you want to load a polynomial from.\n"<<std::endl;
                std::string fileInput=std::string();
                std::getline(std::cin, fileInput);
                std::cout<<std::endl;
                std::cout<<"Now a polynomial will be attempted to be loaded from your input file.\n"<<std::endl;
                P->inputFromFile(fileInput);

                break;
            }

            case 18:
            {
                std::cout<<"Now you will enter the file name to which you want to store the working polynomial to.\n"<<std::endl;
                std::string fileOutput=std::string();
                std::getline(std::cin, fileOutput);
                std::cout<<std::endl;
                std::cout<<"Now the working polynomial will be attempted to be stored from the program to your output file.\n"<<std::endl;
                P->ouputToFile(fileOutput);

                break;
            }

            case 19:
            {
                if(argc>=2)
                {
                    std::cout<<"Now all the arguments to the program shall be processed so their specified set(s) of operations can be performed on the working polynomial.\n"<<std::endl;
                    for(int argCount=1; argCount<argc; argCount++)
                    {
                        std::fstream PfileStream(argv[argCount]);
                        if(PfileStream.is_open())
                        {
                            std::string PfileStreamInfo=std::string();
                            while(std::getline(PfileStream, PfileStreamInfo))
                            {
                                std::string PfileOperation=std::string();
                                std::stringstream PfileStreamInfoSS(PfileStreamInfo);
                                PfileStreamInfoSS>>PfileOperation;
                                if(PfileOperation=="insert:")
                                {
                                    std::cout<<"Now the term(s) provided by the operation will be inserted into the working polynomial.\n"<<std::endl;

                                    std::string termInsert=std::string();
                                    while(PfileStreamInfoSS>>termInsert)
                                    {
                                        std::stringstream termInsertSS(termInsert);
                                        termInsertSS>>*P;
                                    }
                                }

                                else if(PfileOperation=="print:")
                                {
                                    if(P->getHead()==NULL)
                                    {
                                        std::cout<<"There are currently no terms in the working polynomial to print. Please provide some terms in an operation that can be inserted into the working polynomial in order to print them later.\n"<<std::endl;
                                    }

                                    else
                                    {
                                        std::cout<<"Now all the current terms in the working polynomial will be printed.\n"<<std::endl;
                                        std::cout<<*P;
                                        std::cout<<std::endl;
                                    }
                                }

                                else if(PfileOperation=="+:")
                                {
                                    std::cout<<"Now a second polynomial will be made for you to add to the working polynomial.\n"<<std::endl;
                                    Polynomial* P2=new Polynomial();

                                    std::string termInsert=std::string();
                                    while(PfileStreamInfoSS>>termInsert)
                                    {
                                        std::stringstream termInsertSS(termInsert);
                                        termInsertSS>>*P2;
                                    }

                                    if(P2->getHead()==NULL)
                                    {
                                        std::cout<<"It seems that no terms were provided by the operation to the second polynomial for addition. Thus there are no terms in the second polynomial to print.\n"<<std::endl;
                                    }

                                    else
                                    {
                                        if(P->getHead()!=NULL)
                                        {
                                            if(P->getHead()->getVariable()!=P2->getHead()->getVariable())
                                            {
                                                Term* variableTerm=P2->getHead();
                                                while(variableTerm!=NULL)
                                                {
                                                    variableTerm->setVariable(P->getHead()->getVariable());
                                                    variableTerm=variableTerm->getNext();
                                                }
                                            }
                                        }

                                        std::cout<<"Now all the terms in the second polynomial will be printed for you to see which terms that are about to be added to the working polynomial.\n"<<std::endl;
                                        std::cout<<*P2;
                                        std::cout<<std::endl;
                                    }

                                    std::cout<<"Now the second polynomial will be added to the working polynomial.\n"<<std::endl;
                                    *P=*P+*P2;

                                    if(P->getHead()==NULL)
                                    {
                                        std::cout<<"The addition resulted in the working polynomial having zero value. Thus there are no terms in the working polynomial to print."<<std::endl;
                                    }

                                    else
                                    {
                                        std::cout<<"The sum which is now stored in the working polynomial will be displayed.\n"<<std::endl;
                                        std::cout<<*P;
                                        std::cout<<std::endl;
                                    }

                                    delete P2;
                                    P2=NULL;
                                }

                                else if(PfileOperation=="-:")
                                {
                                    std::cout<<"Now a second polynomial will be made for you to subtract from the working polynomial.\n"<<std::endl;
                                    Polynomial* P2=new Polynomial();

                                    std::string termInsert=std::string();
                                    while(PfileStreamInfoSS>>termInsert)
                                    {
                                        std::stringstream termInsertSS(termInsert);
                                        termInsertSS>>*P2;
                                    }

                                    if(P2->getHead()==NULL)
                                    {
                                        std::cout<<"It seems that no terms were provided by the operation to the second polynomial for subtraction. Thus there are no terms in the second polynomial to print.\n"<<std::endl;
                                    }

                                    else
                                    {
                                        if(P->getHead()!=NULL)
                                        {
                                            if(P->getHead()->getVariable()!=P2->getHead()->getVariable())
                                            {
                                                Term* variableTerm=P2->getHead();
                                                while(variableTerm!=NULL)
                                                {
                                                    variableTerm->setVariable(P->getHead()->getVariable());
                                                    variableTerm=variableTerm->getNext();
                                                }
                                            }
                                        }

                                        std::cout<<"Now all the terms in the second polynomial will be printed for you to see which terms that are about to be subtracted from the working polynomial.\n"<<std::endl;
                                        std::cout<<*P2;
                                        std::cout<<std::endl;
                                    }

                                    std::cout<<"Now the second polynomial will be subtracted from the working polynomial.\n"<<std::endl;
                                    *P=*P-*P2;

                                    if(P->getHead()==NULL)
                                    {
                                        std::cout<<"The subtraction resulted in the working polynomial having zero value. Thus there are no terms in the working polynomial to print.\n"<<std::endl;
                                    }

                                    else
                                    {
                                        std::cout<<"The difference which is now stored in the working polynomial will be displayed.\n"<<std::endl;
                                        std::cout<<*P;
                                        std::cout<<std::endl;
                                    }

                                    delete P2;
                                    P2=NULL;
                                }

                                else if(PfileOperation=="*:")
                                {
                                    std::cout<<"Now a second polynomial will be made for you to multiply by the working polynomial.\n"<<std::endl;
                                    Polynomial* P2=new Polynomial();

                                    std::string termInsert=std::string();
                                    while(PfileStreamInfoSS>>termInsert)
                                    {
                                        std::stringstream termInsertSS(termInsert);
                                        termInsertSS>>*P2;
                                    }

                                    if(P2->getHead()==NULL)
                                    {
                                        std::cout<<"It seems that no terms were provided by the operation to the second polynomial for multiplication. Thus there are no terms in the second polynomial to print.\n"<<std::endl;
                                    }

                                    else
                                    {
                                        if(P->getHead()!=NULL)
                                        {
                                            if(P->getHead()->getVariable()!=P2->getHead()->getVariable())
                                            {
                                                Term* variableTerm=P2->getHead();
                                                while(variableTerm!=NULL)
                                                {
                                                    variableTerm->setVariable(P->getHead()->getVariable());
                                                    variableTerm=variableTerm->getNext();
                                                }
                                            }
                                        }

                                        std::cout<<"Now all the terms in the second polynomial will be printed for you to see which terms that are about to be multiplied by the working polynomial.\n"<<std::endl;
                                        std::cout<<*P2;
                                        std::cout<<std::endl;
                                    }

                                    std::cout<<"Now the second polynomial will be multiplied by the working polynomial.\n"<<std::endl;
                                    *P=*P**P2;

                                    if(P->getHead()==NULL)
                                    {
                                        std::cout<<"The multiplication resulted in the working polynomial having zero value. Thus there are no terms in the working polynomial to print.\n"<<std::endl;
                                    }

                                    else
                                    {
                                        std::cout<<"The product which is now stored in the working polynomial will be displayed.\n"<<std::endl;
                                        std::cout<<*P;
                                        std::cout<<std::endl;
                                    }

                                    delete P2;
                                    P2=NULL;
                                }

                                else if(PfileOperation=="/:")
                                {
                                    std::cout<<"Now a second polynomial will be made for you to divide by the working polynomial.\n"<<std::endl;
                                    Polynomial* P2=new Polynomial();

                                    std::string termInsert=std::string();
                                    while(PfileStreamInfoSS>>termInsert)
                                    {
                                        std::stringstream termInsertSS(termInsert);
                                        termInsertSS>>*P2;
                                    }

                                    if(P2->getHead()==NULL)
                                    {
                                        std::cout<<"It seems that no terms were provided by the operation to the second polynomial for division. Thus there are no terms in the second polynomial to print.\n"<<std::endl;
                                    }

                                    else
                                    {
                                        if(P->getHead()!=NULL)
                                        {
                                            if(P->getHead()->getVariable()!=P2->getHead()->getVariable())
                                            {
                                                Term* variableTerm=P2->getHead();
                                                while(variableTerm!=NULL)
                                                {
                                                    variableTerm->setVariable(P->getHead()->getVariable());
                                                    variableTerm=variableTerm->getNext();
                                                }
                                            }
                                        }

                                        std::cout<<"Now all the terms in the second polynomial will be printed for you to see which terms that are about to be divided by the working polynomial.\n"<<std::endl;
                                        std::cout<<*P2;
                                        std::cout<<std::endl;
                                    }

                                    std::cout<<"Now the second polynomial will be divided by the working polynomial.\n"<<std::endl;
                                    *P=*P/(*P2);

                                    if(P->getHead()==NULL)
                                    {
                                        std::cout<<"The division resulted in the working polynomial having zero or undefined value. Thus there are no terms in the working polynomial to print.\n"<<std::endl;
                                    }

                                    else
                                    {
                                        std::cout<<"The quotient which is now stored in the working polynomial will be displayed.\n"<<std::endl;
                                        std::cout<<*P;
                                        std::cout<<std::endl;
                                    }

                                    delete P2;
                                    P2=NULL;
                                }

                                else if(PfileOperation=="%:")
                                {
                                    std::cout<<"Now a second polynomial will be made for you to modulus by the working polynomial.\n"<<std::endl;
                                    Polynomial* P2=new Polynomial();

                                    std::string termInsert=std::string();
                                    while(PfileStreamInfoSS>>termInsert)
                                    {
                                        std::stringstream termInsertSS(termInsert);
                                        termInsertSS>>*P2;
                                    }

                                    if(P2->getHead()==NULL)
                                    {
                                        std::cout<<"It seems that no terms were provided by the operation to the second polynomial for modulus. Thus there are no terms in the second polynomial to print.\n"<<std::endl;
                                    }

                                    else
                                    {
                                        if(P->getHead()!=NULL)
                                        {
                                            if(P->getHead()->getVariable()!=P2->getHead()->getVariable())
                                            {
                                                Term* variableTerm=P2->getHead();
                                                while(variableTerm!=NULL)
                                                {
                                                    variableTerm->setVariable(P->getHead()->getVariable());
                                                    variableTerm=variableTerm->getNext();
                                                }
                                            }
                                        }

                                        std::cout<<"Now all the terms in the second polynomial will be printed for you to see which terms that are about to be modulus by the working polynomial.\n"<<std::endl;
                                        std::cout<<*P2;
                                        std::cout<<std::endl;
                                    }

                                    std::cout<<"Now the second polynomial will be modulus by the working polynomial.\n"<<std::endl;
                                    *P=*P%*P2;

                                    if(P->getHead()==NULL)
                                    {
                                        std::cout<<"The modulus resulted in the working polynomial having zero or undefined value. Thus there are no terms in the working polynomial to print.\n"<<std::endl;
                                    }

                                    else
                                    {
                                        std::cout<<"The modulus which is now stored in the working polynomial will be displayed.\n"<<std::endl;
                                        std::cout<<*P;
                                        std::cout<<std::endl;
                                    }

                                    delete P2;
                                    P2=NULL;
                                }

                                else if(PfileOperation=="exponent:")
                                {
                                    long long exponent=0;
                                    PfileStreamInfoSS>>exponent;
                                    std::cout<<"Now the working polynomial will be raised to the "<<exponent<<" power.\n"<<std::endl;
                                    P->exponent(exponent);

                                    if(P->getHead()!=NULL)
                                    {
                                        std::cout<<"The exponent result, which is now stored in the working polynomial will be displayed.\n"<<std::endl;
                                        std::cout<<*P;
                                        std::cout<<std::endl;
                                    }

                                    else
                                    {
                                        std::cout<<"The exponentiation resulted in the working polynomial having zero value. Thus there are no terms in the working polynomial to print.\n"<<std::endl;
                                    }
                                }

                                else if(PfileOperation=="square-root:")
                                {
                                    std::cout<<"Now the square root of the working polynomial will be attempted to be taken.\n"<<std::endl;
                                    P->squareRoot();
                                }

                                else if(PfileOperation=="factorial:")
                                {
                                     std::cout<<"Now the working polynomial will be factorialized.\n"<<std::endl;
                                     P->factorial();
                                }

                                else if(PfileOperation=="evaluate:")
                                {
                                    std::cout<<"Now the working polynomial will be evaluated with the number(s) provided by the operation.\n"<<std::endl;

                                    long double evaluateNumber=0;
                                    std::string numbersEvaluate=std::string();
                                    while(PfileStreamInfoSS>>numbersEvaluate)
                                    {
                                        std::stringstream numbersEvaluateSS(numbersEvaluate);
                                        numbersEvaluateSS>>evaluateNumber;
                                        P->evaluate(evaluateNumber);
                                    }
                                }

                                else if(PfileOperation=="zero:")
                                {
                                    std::cout<<"Now the polynomial manipulator program will check if the numbers provided by the operation is/are a zero/zeros of the working polynomial.\n"<<std::endl;

                                    long double zero=0;
                                    std::string zeros=std::string();
                                    while(PfileStreamInfoSS>>zeros)
                                    {
                                        std::stringstream zerosSS(zeros);
                                        zerosSS>>zero;
                                        P->zero(zero);
                                    }
                                }

                                else if(PfileOperation=="rational-zeros:")
                                {
                                    std::cout<<"Now all the possible rational zeros will be attempted to be displayed for the working polynomial.\n"<<std::endl;
                                    P->allRationalZeros();
                                }

                                else if(PfileOperation=="remove:")
                                {
                                    std::cout<<"Now the term(s) provided by the operation will be attempted to be removed from the working polynomial.\n"<<std::endl;

                                    long long coefficient=0;
                                    char variable='\0';
                                    long long exponent=0;
                                    std::string termsRemove=std::string();
                                    while(PfileStreamInfoSS>>termsRemove)
                                    {
                                        std::stringstream termsRemoveSS(termsRemove);
                                        termsRemoveSS>>coefficient>>variable>>exponent;
                                        P->removeTerm(coefficient, variable, exponent);
                                    }
                                }

                                else if(PfileOperation=="number-of-terms:")
                                {
                                    std::cout<<"Now the number of terms currently in the working polynomial will be displayed.\n"<<std::endl;
                                    std::cout<<"There is/are "<<P->getNumberOfTerms()<<" term(s) currently in the working polynomial.\n"<<std::endl;
                                }

                                else if(PfileOperation=="file-input:")
                                {
                                    std::string fileInput=std::string();
                                    std::string fileInput2=std::string();
                                    while(PfileStreamInfoSS>>fileInput)
                                    {
                                        fileInput2+=fileInput+" ";
                                    }

                                    fileInput2=fileInput2.substr(0, fileInput2.find_last_of(" "));
                                    std::cout<<"Now a polynomial will be attempted to be loaded from the input file provided by the operation.\n"<<std::endl;
                                    P->inputFromFile(fileInput2);
                                }

                                else if(PfileOperation=="file-output:")
                                {
                                    std::string fileOutput=std::string();
                                    std::string fileOutput2=std::string();
                                    while(PfileStreamInfoSS>>fileOutput)
                                    {
                                        fileOutput2+=fileOutput+" ";
                                    }
                                    fileOutput2=fileOutput2.substr(0, fileOutput2.find_last_of(" "));
                                    std::cout<<"Now the working polynomial will be attempted to be stored from the program to the output file provided by the operation.\n"<<std::endl;
                                    P->ouputToFile(fileOutput2);
                                }

                                else if(PfileOperation=="clear:")
                                {
                                    std::cout<<"Now your polynomial will be cleared for the insertion of a new set/new sets of terms.\n"<<std::endl;
                                    delete P;
                                    P=NULL;
                                    P=new Polynomial();
                                }

                                else
                                {
                                    std::cout<<"The operation "<<PfileOperation<<" is not a recognizable operation that can be done on the working polynomial.\n"<<std::endl;
                                }
                            }
                        }

                        else
                        {
                            std::cout<<"There was an error opening the file "<<argv[argCount]<<". Please try to re-format or re-pass the file as an argument to the program to see if it can open then.\n"<<std::endl;
                        }
                    }
                }

                else
                {
                    std::cout<<"You have not provided any arguments to the program to perform a set/sets of operations on it. Please run the program via command line in order to pass arguments to the program that can specify which set(s) of operations to be done on the working polynomial.\n"<<std::endl;
                }

                break;
            }

            default:
            {
                break;
            }
        }

        std::cout<<"Now a menu will be re-created showing the possible operations that can be done on the working polynomial for reminding purposes.\n"<<std::endl;
        std::cout<<"1. Insert a term/a number of terms into the working polynomial."<<std::endl;
        std::cout<<"2. Print out the current terms in the working polynomial."<<std::endl;
        std::cout<<"3. Add another polynomial to the working polynomial."<<std::endl;
        std::cout<<"4. Subtract another polynomial from the working polynomial."<<std::endl;
        std::cout<<"5. Multiply the working polynomial by another polynomial."<<std::endl;
        std::cout<<"6. Divide the working polynomial by another polynomial."<<std::endl;
        std::cout<<"7. Modulus the working polynomial by another polynomial."<<std::endl;
        std::cout<<"8. Exponentiate the working polynomial by a certain exponent."<<std::endl;
        std::cout<<"9. Take the square root of the working polynomial."<<std::endl;
        std::cout<<"10. Factorialize the working polynomial."<<std::endl;
        std::cout<<"11. Evaluate the working polynomial by a certain number/certain numbers."<<std::endl;
        std::cout<<"12. Input a number/set of numbers to see if it/they is/are a zero/zeros of the working polynomial or not."<<std::endl;
        std::cout<<"13. Retrieve all the possible rational zeros of the working polynomial."<<std::endl;
        std::cout<<"14. Remove a term/a number of terms from the working polynomial."<<std::endl;
        std::cout<<"15. View the current number of terms in the working polynomial."<<std::endl;
        std::cout<<"16. Clear the working polynomial for the insertion of a new set/new sets of terms."<<std::endl;
        std::cout<<"17. Load a polynomial from a file to overwrite the working polynomial with."<<std::endl;
        std::cout<<"18. Store the working polynomial to a file for future use."<<std::endl;
        std::cout<<"19. If running the program on command line and the program has arguments, use the arguments to perform a set of operations on the polynomial manipulator program."<<std::endl;
        std::cout<<"20. Quit the polynomial manipulator program.\n"<<std::endl;

        std::cout<<"Please enter your next choice of operation on the working polynomial by entering the number associated with its description.\n"<<std::endl;
        std::getline(std::cin, menuChoice);
        std::cout<<std::endl;
        menuChoiceSS.str(std::string());
        menuChoiceSS.clear();
        menuChoiceSS<<menuChoice;
        menuChoiceSS>>menuChoice2;
    }

    delete P;
    P=NULL;

    return 0;
}
