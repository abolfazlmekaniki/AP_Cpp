#include "../include/banckingSystem.h"
#include "../include/account.h"
#include "../include/currency.h"
#include "../include/customer.h"

BankingSystem::BankingSystem()
{

    std::cout<<"BankingSystem Constructor"<<std::endl;

};
BankingSystem::BankingSystem(const BankingSystem& other):currencies_{other.currencies_},customers_{other.customers_}{

    std::cout<<"BankingSystem Copy Constructor"<<std::endl;

};
BankingSystem::BankingSystem(BankingSystem&& other):currencies_{other.currencies_},customers_{other.customers_}{

    std::cout<<"BankingSystem Move Constructor"<<std::endl;
};

BankingSystem& BankingSystem::operator=(const BankingSystem& other){
    if(this == &other){
        return *this;
    };
    std::cout<<"BankingSystem copy = operator"<<std::endl;
    currencies_ = other.currencies_;
    customers_= other.customers_;
    return *this;

};
BankingSystem& BankingSystem::operator=(BankingSystem&& other){

    std::cout<<"BankingSystem Move = operator"<<std::endl;
    currencies_ = other.currencies_;
    customers_= other.customers_;
    return *this;


};
BankingSystem::~BankingSystem(){
std::cout<<"BankingSystem Deconstructor"<<std::endl;
};


void BankingSystem::addCustomer(Customer* customer){
    customers_.push_back(customer);
};

bool BankingSystem::transfer(Customer* sender, Account* sender_account,
                  Customer* receiver, Account* receiver_account,
                  double amount, const Currency& currency){
                    if(amount>sender_account->get_balance()){
                        // sender_account->balance_-=amount;
                        // receiver_account->balance_+=amount;
                        return true;
                    }
                    return false;
                  };


double BankingSystem::convert(double amount, const Currency& from_currency,
                   const Currency& to_currency) const{

                    return (amount*from_currency.getExchangeRate())/(to_currency.getExchangeRate());

                   };