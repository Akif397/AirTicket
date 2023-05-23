#ifndef FILEREADWRITESVC_H
#define FILEREADWRITESVC_H

#include <iostream>
#include <string>
#include "..\model\Passenger.h"
#include "..\model\Flight.h"
#include "..\model\Ticket.h"

using namespace std;

class FileReadWriteSvc
{
private:

public:
    static void writePassengerInformation(Passenger passenger);
    static void writeFlightInformation();
    static Flight readFlightInformation(int flightNo);
    static Ticket readTicketInformation(int tktNo);
    static void updateFlightTotalSeat(Flight flight, int seat);
    static Passenger matchPassengerInformation(Passenger p);
    static Passenger matchPassengerInformation(string email);
    static int getLineNo(string fileName);
    static void writeTicketInformation(Ticket ticket);
    static int len(string str);
};

#endif