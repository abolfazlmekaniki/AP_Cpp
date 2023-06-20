#include "../include/currency.h"

Currency::Currency(const std::string& name_, double exchange_rate):name{name_},exchangeRate{exchange_rate}{

    std::cout<<"Currency Costructor "<<std::endl;

};
Currency::~Currency(){

        std::cout<<"Currency Decostructor "<<std::endl;
};

std::string Currency::getName(){
    return name;
};
double Currency::getExchangeRate(){
    return exchangeRate;
};