#include "../include/creditAccount.h"
#include <string>
CreditAccount::CreditAccount(double balance_, double credit_limit)
:Account{balance_},creditLimit{credit_limit},debt{0}{

        std::cout<<"CreditAccount Constructor ✅"<<std::endl;
};

CreditAccount::~CreditAccount(){
    std::cout<<"CreditAccount Deconstructor ❌ "<<std::endl;
};

CreditAccount::CreditAccount(const CreditAccount& v)
:Account{v},creditLimit{v.creditLimit},debt{0}{

    std::cout<<"CreditAccount Copy Constructor ✅"<<std::endl;
};

CreditAccount::CreditAccount(CreditAccount&& v)
:Account{std::move(v)},creditLimit{v.creditLimit},debt{0}
{
    std::cout<<"CreditAccount Move Constructor ✅"<<std::endl;
};


bool CreditAccount::withdraw(double amount){
    std::cout<<"CreditAccount withdraw"<<std::endl;
    
    if(amount>this->get_balance()){
        debt = amount - this->get_balance();
        Account::withdraw(amount);
        std::cout<<"dept is : "<<debt;
        creditLimit-=debt;
        std::cout<<"creditlimit is : "<<creditLimit;
    }
    else{
        Account::withdraw(amount);
        debt=0;
        creditLimit-=debt;
        std::cout<<"dept is : "<<debt;
        std::cout<<"creditlimit is : "<<creditLimit;
    }
};

double CreditAccount::getCreditLimit(){
    return creditLimit;
};

// double CreditAccount::getInterestRate(){
//     return interestRate;
// };

double CreditAccount::getDebt(){
    return debt;
};

void CreditAccount::payDebt(){
        if(debt==0){
             std::cout<<"your dept is zero you shouldn't pay back anything"<<std::endl;
        }
        else{
            
            creditLimit+=debt;
            debt=0;
        }
    
};