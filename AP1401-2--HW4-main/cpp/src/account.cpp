#include "../include/account.h"


Account::Account(double balance ):balance_{balance}{
    std::cout<<"Account Constructor"<<std::endl;
};

Account::~Account(){
    std::cout<<"Account Destructor"<<std::endl;
    delete x;
};

Account::Account(const Account& v):balance_{v.balance_}{

    std::cout<<"Account Copy Constructor "<<std::endl;

};

Account::Account(Account&& v):balance_{v.balance_}{

    std::cout<<"Account Move Constructor "<<std::endl;

};


Account& Account::operator=(const Account& v){
    std::cout<<"Account Operator = : Copy Version";
    if(this == &v){
        return *this;
    }
    balance_ = v.balance_;
    transactions_.clear();
    for(size_t i=0;i<v.transactions_.size();i++){
        transactions_[i]=v.transactions_[i];
    }
    return *this;
};


Account& Account::operator=(Account&& v){
    std::cout<<"Account Operator = : Move Version";
    balance_ = v.balance_;
    transactions_ = v.transactions_;
    return *this;
};


 void Account::deposit(double amount){
    if(amount>=0){
        balance_ += amount;
        x = new Transaction{"deposit","this account ",amount,"USDT"};
        transactions_.push_back(*x);
        std::cout<<"deposit accoured : "<<(*x).getAmount()<<" USDT "<<std::endl;
    }
 };

bool Account::withdraw(double amount){

    if(balance_>=amount && amount>=0){
        balance_ -=amount;
        x = new Transaction{"withdraw","this account ",amount,"USDT"};
        transactions_.push_back(*x);
        std::cout<<"Withdraw accoured : "<<(*x).getAmount()<<" USDT "<<std::endl;
        return true;
    }
    return false;
};


double Account::get_balance(){
    // for (auto &element : transactions_) {
    //     std::cout<<"element : "<< element.getAmount() <<std::endl;
    // }
    return balance_;
};