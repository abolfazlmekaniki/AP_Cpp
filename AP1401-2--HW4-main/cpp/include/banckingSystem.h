#ifndef BACKING_H
#define BANKING_H

#include <iostream>
#include <vector>
#include "customer.h"
class BankingSystem {
public:
    BankingSystem();
    ~BankingSystem();
    BankingSystem(const BankingSystem& other);
    BankingSystem(BankingSystem&& other);
    BankingSystem& operator=(const BankingSystem& other);
    BankingSystem& operator=(BankingSystem&& other);
    void addCustomer(Customer* customer);
    bool transfer(Customer* sender, Account* sender_account,
                  Customer* receiver, Account* receiver_account,
                  double amount, const Currency& currency);
    double convert(double amount, const Currency& from_currency,
                   const Currency& to_currency) const;

private:
    std::vector<Customer*> customers_;
    std::vector<Currency> currencies_;
};


#endif