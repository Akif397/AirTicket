#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
#include "service\DisplaySvc.h"
#include "service\FileReadWriteSvc.h"

using namespace std;

int main()
{
    int flightNumber = FileReadWriteSvc::getLineNo("Flight.txt");
    if (flightNumber == 0)
    {
        FileReadWriteSvc::writeFlightInformation();
    }

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