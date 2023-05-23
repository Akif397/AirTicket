#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include "Passenger.h"
#include "Flight.h"

using namespace std;

class Ticket
{
private:
    int id;
    Passenger passenger;
    Flight flight;
    int seatNumber;
    string status;
public:
    void setId();
    void setId(int id);
    void setPassenger(Passenger passenger);
    void setFlight(Flight flight);
    void setStatus(string status);
    void setSeatNumber(int seatNumber);
    int getId();
    Passenger getPassenger();
    Flight getFlight();
    string getStatus();
    int getSeatNumber();
};

#endif