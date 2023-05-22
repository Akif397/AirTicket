#include <iostream>
#include "Passenger.h"

using namespace std;

string Passenger::getEmail(){
    return this->email;
}

string Passenger::getName(){
    return this->name;
}

string Passenger::getPassword(){
    return this->password;
}

bool Passenger::getIsLoggedIn(){
    return this->isLoggedIn;
}

bool Passenger::getIsHomePageButtonClicked(){
    return this->isHomePageButtonClicked;
}

void Passenger::setName(string name){
    this->name = name;
}

void Passenger::setEmail(string email){
    this->email = email;
}

void Passenger::setPassword(string password){
    this->password = password;
}

void Passenger::setIsLoggedIn(bool isLoggedIn){
    this->isLoggedIn = isLoggedIn;
}

void Passenger::setIsHomePageButtonClicked(bool isHomePageButtonClicked){
    this->isHomePageButtonClicked = isHomePageButtonClicked;
}