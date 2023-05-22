#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Air.h"
#include "service\DisplaySvc.h"
#include "service\FileReadWriteSvc.h"

using namespace std;

class EconAirBus
{
private:
    int totalSeat;
    double ticketPrice;
};

class BusinessAirBus
{
private:
    int totalSeat;
    double ticketPrice;
};

class Airbus
{
private:
    const string name = "Turkish Airlines";
    string abID;
    string dest;
    string dept;
    string deptTime;
    EconAirBus economy;
    BusinessAirBus business;

public:
    Airbus()
    {
    }

    string getAbId()
    {
        return this->abID;
    }

    void setAbId()
    {
        this->abID = "TK" + to_string(rand());
    }
};

void writeAirBusDetailsToFile(Airbus airbus)
{
    ofstream myfile;
    myfile.open("flight_details.txt");
    myfile << "#############\n";
    myfile << airbus.getAbId() + "\n";
    myfile.close();
}

class Admin
{
private:
    int id;
    string name;

public:
    Admin()
    {
        cout << "Admin created." << endl;
    }
};

int main()
{
    FileReadWriteSvc::writeFlightInformation();
    // Admin admin;

    // Airbus air;

    // writeAirBusDetailsToFile(air);
    // cout << "Hello world";

    // Air a("Biman");
    // a.print();

    // DisplaySvc d;
    // d.displayHomepage();

    // bool exit = false;
    // while (exit == false)
    // {
    //     int homePageInput;
    //     bool isLoggedIn = false;
    //     DisplaySvc::displayHomepage();

    //     cin >> homePageInput;
    //     cout << endl;
    //     if (homePageInput == 1 || homePageInput == 2)
    //     {
    //         while (!isLoggedIn)
    //         {
    //             Passenger passenger = DisplaySvc::displayLoginpage();
    //             if (!passenger.getIsLoggedIn())
    //             {
    //                 cout << "Credential does not match" << endl;
    //             }
    //             isLoggedIn = passenger.getIsLoggedIn();
    //         }
    //     }
    //     else
    //     {
    //         cout << "Wrong input" << endl;
    //     }
    // }

    // srand(time(0));
    // for (int i = 0; i < 100; i++)
    // {
    //     cout << rand() % 9 << endl;
    // }

    // FileReadWriteSvc::readPassengerInformation();
}