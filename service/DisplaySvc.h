#ifndef DISPLAYSVC_H
#define DISPLAYSVC_H

#include <iostream>
#include "..\model\Passenger.h"

using namespace std;

class DisplaySvc
{
public:
    static void displayHomepage();
    static Passenger displayLoginpage();
    static Passenger displayRegisterpage();
};

#endif