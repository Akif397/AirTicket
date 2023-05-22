#ifndef FILEREADWRITESVC_H
#define FILEREADWRITESVC_H

#include <iostream>
#include <string>
#include "..\model\Passenger.h"
#include "..\model\Flight.h"

using namespace std;

class FileReadWriteSvc
{
private:

public:
    static void writePassengerInformation(Passenger passenger);
    static void writeFlightInformation();
    static Flight readFlightInformation();
    static Passenger matchPassengerInformation(Passenger p);
    static int len(string str);
};

#endif