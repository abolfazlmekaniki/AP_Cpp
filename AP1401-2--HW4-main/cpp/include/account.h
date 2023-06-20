#ifndef ACOOUNT_H
#define ACOOUNT_H

#include <iostream>
#include "./transaction.h"
#include <vector>
class Account {
public:
    Account(double balance = 0);
    ~Account();
    Account(const Account&);
    Account(Account&&);
    Account& operator=(const Account&);
    Account& operator=(Account&&);

    void deposit(double amount);
    virtual bool withdraw(double amount);
    double get_balance();

    std::vector<Transaction> transactions_;

private:
    double balance_;
    Transaction* x;
};

#endif