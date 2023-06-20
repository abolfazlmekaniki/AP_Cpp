#include "../include/hw2.h"
#include<iostream>
#include<string>
#include <fstream> 
#include<iomanip>
#include<math.h>
#include <string>
#include<sstream>
#include <cmath>

User::User(std::string name, std::string pass, std::string mail){
    username = name;
    password = pass;
    email = mail ;
   
};

User::~User(){
}

Login::Login(){};
Login::~Login(){};





void Login::registerUser(std::string username, std::string password, std::string email){

        bool registered=false;
        for(int t=0; t<static_cast<int> (users.size());t++){
            
            if(checkUsername(username)){
             
                registered=true;
                break;
            }
            else if (checkEmail(email)){
                
                registered=true;
                break;
            }
        }

        if(registered == false){
                User* new_usr=new User{username,password,email};
                users.push_back(new_usr); 
        }
};


void Login::loginUser(std::string username, std::string password){

    if(users.size()!= 0){

        bool logedin = false;
       
        for(int t=0; t<static_cast<int> (users.size());t++){

            if((users[t])->username==username && (users[t])->password==password){


                        for(int i = 0 ; i<static_cast<int> (LoginedUsers.size());i++){

                            if(LoginedUsers[i]->username==username){
                                logedin = true;
                                break;

                            }
                        }

                        if(logedin == false){
                                LoginedUsers.push_back(users[t]); 
                        }
                    }
                
        }
    }
};

User* Login::getUser (std::string username){

    for(int t=0; t<static_cast<int> (users.size());t++){

        if(users[t]->username == username){
            
            return users[t];
        }

    };
    return nullptr;
};

bool Login::checkUsername(std::string &new_username){

    std::string new_user =new_username;

    for(int t=0; t<static_cast<int> (users.size());t++){
        if(users[t]->username == new_user){
            
            return true;
        }

    };
    return false;
};

bool Login::checkEmail(std::string &new_email){

    std::string newemail =new_email;

    for(int t=0; t<static_cast<int> (users.size());t++){
        if(users[t]->email == newemail){
            return true;
        }

    };
    return false;
};


void Login::changePassword(std::string username, std::string newPassword){

    for(int t=0; t<static_cast<int> (users.size());t++){

        if(users[t]->username == username){
           
            users[t]->password = newPassword;
            
        }
    };
};

void Login::changeUsername(std::string username, std::string newUsername){

    std::string new_Username = newUsername;

    for(int t=0; t<static_cast<int> (users.size());t++){

        if(users[t]->username == username && !checkUsername(new_Username)){

            users[t]->username = new_Username;
        }
    };
};

void Login::changeMail(std::string username, std::string newMail){

    std::string new_mail = newMail;

    for(int t=0; t<static_cast<int> (users.size());t++){

        if(users[t]->username == username && ! checkEmail(new_mail)){
    
            users[t]->email = new_mail;
            
        }
    };
};


 void Login::removeUser(std::string username){

        for(int t=0; t<static_cast<int> (users.size());t++){

            if(users[t]->username == username){

                users.erase(users.begin()+t);
                break;
            }
        };

        if(static_cast<int> (LoginedUsers.size())){

            for(int t=0; t<static_cast<int> (LoginedUsers.size());t++){

                if(LoginedUsers[t]->username == username){

                    LoginedUsers.erase(LoginedUsers.begin()+t);
                    break;
                }
            }
        }
        

 };


 void Login::readFile(std::string path){
    std::ifstream data(path);
    std::string mystring,user_name,pass_word,email,status;
    std::getline(data,mystring);
    while(std::getline(data,mystring))
    {
        std::stringstream my_Data(mystring);
        my_Data>>user_name>>pass_word>>email>>status;
        registerUser(user_name,pass_word,email);
        if(status=="yes"){
            loginUser(user_name,pass_word);
        };
    }
}