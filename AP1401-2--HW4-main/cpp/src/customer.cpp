#include "../include/customer.h"
#include "../include/account.h"
#include "../include/currency.h"


Customer::Customer(const std::string& name_, const std::string& password_):name{name_},password{password_}
{

    std::cout<<"Customer Constructor"<<std::endl;

};
Customer::Customer(const Customer& other):password{other.password},name{other.name}{

    std::cout<<"Customer Copy Constructor"<<std::endl;

};
Customer::Customer(Customer&& other):password{other.password},name{other.name}{

    std::cout<<"Customer Move Constructor"<<std::endl;
};
Customer& Customer::operator=(const Customer& other){
    if(this == &other){
        return *this;
    };
    std::cout<<"Customer copy = operator"<<std::endl;
    password = other.password;
    name = other.name;
    return *this;

};
Customer& Customer::operator=(Customer&& other){

    std::cout<<"Customer Move = operator"<<std::endl;
    password = other.password;
    name = other.name;
    return *this;


};
Customer::~Customer(){
std::cout<<"Customer Deconstructor"<<std::endl;
};

bool Customer::authenticate(const std::string& password_){
    if(password==password_){
        return true;
    }
    return false;
};
void Customer::addAccount(Account* account, const Currency& currency){

    accounts[&currency].push_back(account);
    std::cout<<"account added "<<std::endl;

};

std::vector<Account*>& Customer::getAccounts(const Currency& currency){
    for (auto x : accounts){
        if(x.first== &currency){
            return x.second;
        }
    }
    // cout << x.first << " " << 
    //         x.second << endl;
    // return accounts[&currency]
};