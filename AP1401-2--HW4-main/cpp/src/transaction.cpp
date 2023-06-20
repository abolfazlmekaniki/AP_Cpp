#include "../include/transaction.h"


Transaction::Transaction(const std::string& from_, const std::string& to_, double amount_, const std::string& currency_)
:from{from_},to{to_},amount{amount_},currency{currency_}
{

    std::cout<<"Transaction's Constructor "<<std::endl<<std::endl;


};

Transaction::~Transaction(){
     std::cout<<"Transaction's Deconstructor "<<std::endl<<std::endl;
};


std::string Transaction::getFrom(){
    return from;
};

std::string Transaction::getTo(){
    return to;
};

double Transaction::getAmount(){
    return amount;
};

std::string Transaction::getCurrency(){
    return currency;
};