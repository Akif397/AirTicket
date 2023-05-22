#include <iostream>
#include "DisplaySvc.h"
#include "..\model\Passenger.h"
#include "FileReadWriteSvc.h"

using namespace std;

void DisplaySvc::displayHomepage()
{
    cout << "## Home Page ## Welcome To the Bowie Airlines." << endl;
    cout << "Press -> 1 <- to Buy Ticket." << endl;
    cout << "Press -> 2 <- to Cancel Ticket." << endl;
}

Passenger DisplaySvc::displayLoginpage()
{
    string email, password;
    int input;
    cout << "## Login Page ##" << endl;

    cout << "Press -> 1 <- to Login account." << endl;
    cout << "Press -> 2 <- to Register new account." << endl;
    cout << "Press -> 0 <- to Return home page." << endl;
    cin >> input;
    cout << endl;

    Passenger passenger;

    if (input == 1)
    {
        cout << "Enter your email: ";
        cin >> email;
        cout << endl;

        cout << "Enter your password: " << endl;
        cin >> password;
        cout << endl;

        passenger.setEmail(email);
        passenger.setPassword(password);

        passenger = FileReadWriteSvc::matchPassengerInformation(passenger);
        passenger.setIsHomePageButtonClicked(false);
    }
    else if (input == 2)
    {
        passenger = displayRegisterpage();
        passenger.setIsHomePageButtonClicked(false);
    } else if (input == 0){
        passenger.setIsLoggedIn(true);
        passenger.setIsHomePageButtonClicked(true);
    }
    
    return passenger;
}

Passenger DisplaySvc::displayRegisterpage()
{
    string firstName, lastName, email, password;
    cout << "## Register Page ##" << endl;

    cout << "Enter your first name: ";
    cin >> firstName;
    cout << endl;

    cout << "Enter your last name: ";
    cin >> lastName;
    cout << endl;

    cout << "Enter your email: ";
    cin >> email;
    cout << endl;

    cout << "Enter your password: " << endl;
    cin >> password;
    cout << endl;

    Passenger passenger;
    passenger.setName(firstName + " " + lastName);
    passenger.setEmail(email);
    passenger.setPassword(password);
    FileReadWriteSvc::writePassengerInformation(passenger);
    return passenger;
}