#include <iostream>
#include "hw1.h"
#include<vector>
#include <memory>
#include <fstream> 
#include<iomanip>
#include<math.h>
#include <string>
#include<sstream>
#include <cmath>

std::vector<std::shared_ptr<std::vector<double>>> read_csv(std::string name){

    // ! read data file .
    std::ifstream myData(name);
    std::string mystring;

    // ! create vector 
    std::vector<double> my_vector{};

    // ! create shared_ptr
    std::shared_ptr<std::vector<double>> result;


    // ! difine result2 as a vector of shared_ptr 
    std::vector<std::shared_ptr<std::vector<double>>> result2;



    while ( std::getline (myData, mystring) ) {

        my_vector={};

        std::stringstream line_mystring(mystring);
        std::string section;

        for(int t{};t<2;t++){

            std::getline (line_mystring,section,',');
            my_vector.push_back(stod(section));
        }
        std::getline (line_mystring, section);
        my_vector.push_back(stod(section));

        result=std::make_shared<std::vector<double>>( my_vector);

        result2.push_back(result);


    };

    return result2;
};
    

double sigmoid(double number){

    return 1.0 / (1.0+ exp(-number));

};


std::vector<double> train(std::vector<std::shared_ptr<std::vector<double>>> train_data ,double learning_rate,int num_iter){

    int train_item {static_cast<int> (train_data.size())};
    double w1{0.3};
    double w2{0.5};
    double b{0.7};
    double output{};

    for(int i{};i<num_iter;i++){

        for(int j{};j<train_item;j++){

            output = predict(*train_data[j],{b,w1,w2});    

            w1=w1+(learning_rate*(-output+train_data[j]->at(2))*(train_data[j]->at(0)));

            w2=w2+(learning_rate*(-output+train_data[j]->at(2))*(train_data[j]->at(1)));

        };
        
    }

    std::vector<double> res{w1,w2,b};
    return res;

};




int predict(std::vector<double> orginal_data,std::vector<double> weights){
    

    double w1_{weights[1]};
    double w2_{weights[2]};
    double output{};
    double b_{weights[0]};
    
    double z{};

    z=(orginal_data[0])*w1_ +(orginal_data[1])*w2_ + b_;
    
    output=sigmoid(z);
    
    if(output>=0.5){
       
        return 1;
    }
    else{
        
        return 0;
    }

};


double accuracy(std::vector<std::shared_ptr<std::vector<double>>> orginal_data, std::vector<double> weights)
{

    int data_size { static_cast<int>(orginal_data.size()) };
  
    double acc{};

    for (int t{};t<data_size;t++){

        if(predict(*orginal_data[t], weights)== (orginal_data[t]->at(2))){
            acc++;
        }

    };

    return (acc/data_size)*100 ;
    
}