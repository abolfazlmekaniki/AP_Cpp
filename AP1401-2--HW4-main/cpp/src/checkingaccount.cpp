#include "../include/checkingaccount.h"

CheckingAccount::CheckingAccount(double balance_, double fee_)
:Account{balance_},fee{fee_}{

        std::cout<<"CheckingAccount Constructor ✅"<<std::endl;
};

CheckingAccount::~CheckingAccount(){
    std::cout<<"CheckingAccount Deconstructor ❌ "<<std::endl;
};

CheckingAccount::CheckingAccount(const CheckingAccount& v)
:Account{v},fee{v.fee}{

    std::cout<<"CheckingAccount Copy Constructor ✅"<<std::endl;
};

CheckingAccount::CheckingAccount(CheckingAccount&& v)
:Account{std::move(v)},fee{v.fee}
{
    std::cout<<"CheckingAccount Move Constructor ✅"<<std::endl;
};

CheckingAccount& CheckingAccount::operator=(const CheckingAccount& v){
    std::cout<<"CheckingAccount Operator = : Copy version"<<std::endl;
    Account::operator=(v);
    // interestRate = v.interestRate;
};

CheckingAccount& CheckingAccount::operator=(CheckingAccount&& v){
    std::cout<<"CheckingAccount Operator = : Move version"<<std::endl;
    Account::operator=(std::move(v));
    // interestRate = v.interestRate;
};

bool CheckingAccount::withdraw(double amount){
        std::cout<<"CheckingAccount withdraw"<<std::endl;
        return Account::withdraw(amount+fee);

};

void CheckingAccount::deposit(double amount){
    Account::deposit(amount-fee);
    std::cout<<"CheckingAccount deposite "<<std::endl;
};