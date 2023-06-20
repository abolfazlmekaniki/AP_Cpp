#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
class Transaction {
public:
    Transaction(const std::string& from, const std::string& to, double amount, const std::string& currency);
    ~Transaction();
    std::string getFrom();
    std::string getTo();
    double getAmount();
    std::string getCurrency();

private:
    std::string from;
    std::string to;
    double amount;
    std::string currency;
};




#endif