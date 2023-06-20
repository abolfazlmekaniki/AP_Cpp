#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include <iostream>
#include "./account.h"
class CheckingAccount: public Account {
public:
    CheckingAccount(double balance = 0, double fee = 1);
    ~CheckingAccount();
    CheckingAccount(const CheckingAccount&);
    CheckingAccount(CheckingAccount&&);
    CheckingAccount& operator=(const CheckingAccount&);
    CheckingAccount& operator=(CheckingAccount&&);
    virtual bool withdraw(double amount) override;
    virtual void deposit(double amount) override;
private:
    double fee;
};





#endif