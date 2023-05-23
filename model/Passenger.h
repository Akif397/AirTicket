#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>

using namespace std;

class Passenger
{
private:
    string name;
    string email;
    string password;
    bool isLoggedIn = false;
    bool isHomePageButtonClicked = false;

public:
    void setName(string name);
    void setEmail(string email);
    void setPassword(string password);
    void setIsLoggedIn(bool isLoggedIn);
    void setIsHomePageButtonClicked(bool isHomePageButtonClicked);
    string getName();
    string getEmail();
    string getPassword();
    bool getIsLoggedIn();
    bool getIsHomePageButtonClicked();
};

#endif