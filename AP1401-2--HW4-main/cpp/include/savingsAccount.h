#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H
#include <iostream>
#include "./account.h"
class SavingsAccount: public Account {
public:
    SavingsAccount(double balance = 0, double interest_rate = 0.01);
    ~SavingsAccount();
    SavingsAccount(const SavingsAccount&);
    SavingsAccount(SavingsAccount&&);
    SavingsAccount& operator=(const SavingsAccount&);
    SavingsAccount& operator=(SavingsAccount&&);
    void addInterest(double amount);
    virtual bool withdraw(double amount) override;

private:
    double interestRate;
    size_t withdrawCounts;
};






#endif