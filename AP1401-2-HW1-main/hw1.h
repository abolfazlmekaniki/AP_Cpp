#include<vector>
#include<iostream>
#include <memory>
#include <fstream> 
#include <string>
#ifndef HW1_H
#define HW1_H
// std::vector<std::shared_ptr<std::vector<double>>>
std::vector<std::shared_ptr<std::vector<double>>> read_csv(std::string name);

double sigmoid(double number);


std::vector<double> train(std::vector<std::shared_ptr<std::vector<double>>> train_data ,double learning_rate,int num_iter);


int predict(std::vector<double> orginal_data,std::vector<double> weights);

double accuracy(std::vector<std::shared_ptr<std::vector<double>>> train_data, std::vector<double> weights);

#endif