#ifndef CREDITACCOUNT_H
#define CREDITACCOUNT_H
#include <iostream>
#include "./account.h"
class CreditAccount:public Account {
public:
    CreditAccount(double balance = 0, double credit_limit = 500);
    ~CreditAccount();
    CreditAccount(const CreditAccount& other);
    CreditAccount(CreditAccount&& other);
    virtual bool withdraw(double amount) override;
    double getCreditLimit();
    // double getInterestRate();
    double getDebt();
    void payDebt();

private:
    double creditLimit;
    double debt;
};

#endif