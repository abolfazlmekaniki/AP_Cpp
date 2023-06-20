#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <vector>
#include "account.h"
#include "currency.h"
#include <unordered_map>
class Customer {
public:
    Customer(const std::string& name, const std::string& password);
    Customer(const Customer& other);
    Customer(Customer&& other);
    Customer& operator=(const Customer& other);
    Customer& operator=(Customer&& other);
    ~Customer();
    bool authenticate(const std::string& password);
    void addAccount(Account* account, const Currency& currency);
    std::vector<Account*>& getAccounts(const Currency& currency);

private:
    std::string name;
    std::string password;

    std::unordered_map<const Currency*,std::vector<Account*>> accounts;
};





#endif