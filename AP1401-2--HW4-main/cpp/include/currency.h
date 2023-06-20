#ifndef CURRENCY_H
#define CURRENCY_H
#include <iostream>
class Currency {
public:
    Currency(const std::string& name, double exchange_rate);
    ~Currency();
    std::string getName();
    double getExchangeRate();

private:
    std::string name;
    double exchangeRate;
};






#endif