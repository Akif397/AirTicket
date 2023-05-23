#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>

using namespace std;

class Flight
{
private:
    int id;
    string name;
    string departure;
    string destination;
    string deptTime;
    int totalSeat;

public:
    void setId(int id);
    void setName(string name);
    void setDeparture(string departure);
    void setDestination(string destination);
    void setdeptTime(string deptTime);
    void setTotalSeat(int totalSeat);

    int getId();
    string getName();
    string getDeparture();
    string getDestination();
    string getDeptTime();
    int getTotalSeat();
};

#endif