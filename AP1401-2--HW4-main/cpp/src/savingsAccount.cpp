#include "../include/savingsAccount.h"


SavingsAccount::SavingsAccount(double balance_, double interest_rate)
:Account{balance_},interestRate{interest_rate},withdrawCounts{0}{

        std::cout<<"SavingsAcoount Constructor ✅"<<std::endl;
};

SavingsAccount::~SavingsAccount(){
    std::cout<<"SavingsAcoount Deconstructor ❌ "<<std::endl;
};

SavingsAccount::SavingsAccount(const SavingsAccount& v)
:Account{v},interestRate{v.interestRate}{

    std::cout<<"SavingsAcoount Copy Constructor ✅"<<std::endl;
};

SavingsAccount::SavingsAccount(SavingsAccount&& v)
:Account{std::move(v)},interestRate{v.interestRate}
{
    std::cout<<"SavingsAcoount Move Constructor ✅"<<std::endl;
};

SavingsAccount& SavingsAccount::operator=(const SavingsAccount& v){
    std::cout<<"SavingsAcoount Operator = : Copy version"<<std::endl;
    Account::operator=(v);
    interestRate = v.interestRate;
};

SavingsAccount& SavingsAccount::operator=(SavingsAccount&& v){
    std::cout<<"SavingsAcoount Operator = : Move version"<<std::endl;
    Account::operator=(std::move(v));
    interestRate = v.interestRate;
};

void SavingsAccount::addInterest(double amount){
    interestRate+=amount;
};
bool SavingsAccount::withdraw(double amount){
    std::cout<<"withdrawCounts : "<<withdrawCounts<<std::endl;
    if(withdrawCounts<3){
        Account::withdraw(amount);
        withdrawCounts++;
        return true;
    }
    return false;
};