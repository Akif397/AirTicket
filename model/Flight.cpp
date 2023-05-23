#include <iostream>
#include "Flight.h"

using namespace std;

int Flight::getId(){
    return this->id;
}

string Flight::getName(){
    return this->name;
}

string Flight::getDeparture(){
    return this->departure;
}

string Flight::getDestination(){
    return this->destination;
}

string Flight::getDeptTime(){
    return this->deptTime;
}

int Flight::getTotalSeat(){
    return this->totalSeat;
}

void Flight::setId(int id){
    this->id = id;
}

void Flight::setName(string name){
    this->name = name;
}

void Flight::setDeparture(string departure){
    this->departure = departure;
}

void Flight::setDestination(string destination){
    this->destination = destination;
}

void Flight::setdeptTime(string deptTime){
    this->deptTime = deptTime;
}

void Flight::setTotalSeat(int totalSeat){
    this->totalSeat = totalSeat;
}