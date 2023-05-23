#ifndef DISPLAYSVC_H
#define DISPLAYSVC_H

#include <iostream>
#include "..\model\Passenger.h"
#include "..\model\Ticket.h"
#include "..\model\Flight.h"

using namespace std;

class DisplaySvc
{
public:
    static void displayHomepage();
    static Passenger displayLoginpage();
    static Passenger displayRegisterpage();
    static Passenger displayAllFlightDetails(Passenger passenger);
    static Passenger displayAllTicketDetails(Passenger passenger);
    static Passenger displayFlightDetails(Flight flight, Passenger passenger);
    static Ticket buyTicket(Flight flight, Passenger passenger, int seat);
};

#endif