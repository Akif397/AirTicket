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
    int flightNumber = FileReadWriteSvc::getLineNo("Flight.txt");
    if (flightNumber == 0)
    {
        FileReadWriteSvc::writeFlightInformation();
    }

    DisplaySvc::displayHomepage();

    bool exit = false;
    while (exit == false)
    {
        int homePageInput;
        bool isLoggedIn = false;
        DisplaySvc::displayHomepage();

        cin >> homePageInput;
        cout << endl;
        Passenger passenger;
        if (homePageInput == 1)
        {
            while (!isLoggedIn)
            {
                passenger = DisplaySvc::displayLoginpage();

                if (passenger.getIsHomePageButtonClicked())
                {
                    break;
                }
                else if (!passenger.getIsLoggedIn())
                {
                    cout << "Credential does not match" << endl;
                }
                else if (passenger.getIsLoggedIn())
                {
                    passenger = DisplaySvc::displayAllFlightDetails(passenger);
                    if (!passenger.getIsLoggedIn())
                    {
                        break;
                    }
                    while (passenger.getIsLoggedIn() && passenger.getIsHomePageButtonClicked())
                    {
                        passenger = DisplaySvc::displayAllFlightDetails(passenger);
                        if (!passenger.getIsLoggedIn())
                        {
                            break;
                        }
                    }
                }
                if (!passenger.getIsLoggedIn())
                {
                    isLoggedIn = passenger.getIsLoggedIn();
                }
            }
        }
        else if (homePageInput == 2)
        {
            while (!isLoggedIn)
            {
                passenger = DisplaySvc::displayLoginpage();

                if (passenger.getIsHomePageButtonClicked())
                {
                    break;
                }
                else if (!passenger.getIsLoggedIn())
                {
                    cout << "Credential does not match" << endl;
                }
                else if (passenger.getIsLoggedIn())
                {
                    passenger = DisplaySvc::displayAllTicketDetails(passenger);
                    if (!passenger.getIsLoggedIn())
                    {
                        break;
                    }
                    while (passenger.getIsLoggedIn())
                    {
                        passenger = DisplaySvc::displayAllTicketDetails(passenger);
                        if (!passenger.getIsLoggedIn())
                        {
                            break;
                        }
                    }
                }
                // if (!passenger.getIsLoggedIn())
                // {
                //     isLoggedIn = passenger.getIsLoggedIn();
                // }
            }
        }
        else
        {
            cout << "Wrong input" << endl;
        }
    }

    // srand(time(0));
    // for (int i = 0; i < 100; i++)
    // {
    //     cout << rand() % 9 << endl;
    // }

    // FileReadWriteSvc::readPassengerInformation();
}