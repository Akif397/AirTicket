#include <iostream>
#include "DisplaySvc.h"
#include "..\model\Passenger.h"
#include "..\model\Ticket.h"
#include "FileReadWriteSvc.h"

using namespace std;

void DisplaySvc::displayHomepage()
{
    cout << "## Home Page ## Welcome To the Bowie Airlines." << endl;
    cout << "Press -> 1 <- to Buy Ticket." << endl;
    cout << "Press -> 2 <- to Cancel Ticket." << endl;
}

Passenger DisplaySvc::displayAllFlightDetails(Passenger passenger)
{
    int totalFlights = FileReadWriteSvc::getLineNo("Flight.txt");
    int input;
    Flight *flights = new Flight[totalFlights];
    for (int i = 0; i < totalFlights; i++)
    {
        Flight flight = FileReadWriteSvc::readFlightInformation(i);
        string data = "Press-> " + to_string(flight.getId()) + " <- for Flight Name: " + flight.getName() + " from: " + flight.getDeparture() + " to: " + flight.getDestination() + " at: " + flight.getDeptTime();
        cout << data << endl;
    }
    cout << "Press -> 0 <- to logout." << endl;
    cin >> input;
    cout << endl;
    if (input == 0)
    {
        passenger.setIsLoggedIn(false);
    }
    else if (input > 0 && input <= 100)
    {
        Flight flight = FileReadWriteSvc::readFlightInformation(input - 1);
        passenger = DisplaySvc::displayFlightDetails(flight, passenger);
    }
    return passenger;
}

Passenger DisplaySvc::displayFlightDetails(Flight flight, Passenger passenger)
{
    int input;
    cout << "##########" << endl;
    cout << "Flight name: " << flight.getName() << endl;
    cout << "Departure: " << flight.getDeparture() << endl;
    cout << "Destination: " << flight.getDestination() << endl;
    cout << "Departure Time(Military Time): " << flight.getDeptTime() << endl;
    cout << "Available Seats: " << to_string(flight.getTotalSeat()) << endl;
    cout << "##########" << endl;

    cout << "Press -> 0 <- to Go Back." << endl;
    cout << "Enter total number of ticket you want to buy. " << endl;
    cin >> input;
    cout << endl;
    if (input == 0)
    {
        passenger.setIsHomePageButtonClicked(true);
    }
    else
    {
        if (input > flight.getTotalSeat())
        {
            cout << "Seats Unavailable." << endl;
        }
        else
        {
            Ticket ticket = DisplaySvc::buyTicket(flight, passenger, input);
            cout << "Ticket no: " << ticket.getId() << " confirmed." << endl;
        }
        passenger.setIsHomePageButtonClicked(true);
    }
    return passenger;
}

Ticket DisplaySvc::buyTicket(Flight flight, Passenger passenger, int seat)
{
    Ticket ticket;
    ticket.setId();
    ticket.setFlight(flight);
    ticket.setPassenger(passenger);
    ticket.setStatus("Bought");
    ticket.setSeatNumber(seat);
    FileReadWriteSvc::writeTicketInformation(ticket);
    FileReadWriteSvc::updateFlightTotalSeat(flight, seat);
    return ticket;
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
    }
    else if (input == 0)
    {
        passenger.setIsLoggedIn(false);
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