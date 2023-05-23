#include <iostream>
#include "Ticket.h"
#include "Flight.h"
#include "Passenger.h"
#include "..\service\FileReadWriteSvc.h"

using namespace std;

int Ticket::getId(){
    return this->id;
}

Passenger Ticket::getPassenger(){
    return this->passenger;
}

Flight Ticket::getFlight(){
    return this->flight;
}

string Ticket::getStatus(){
    return this->status;
}

int Ticket::getSeatNumber(){
    return this->seatNumber;
}

void Ticket::setId(){
    int totalTicketNumber = FileReadWriteSvc::getLineNo("Ticket.txt");
    this->id = totalTicketNumber + 1;
}

void Ticket::setId(int id){
    this->id = id;
}

void Ticket::setPassenger(Passenger passenger){
    this->passenger = passenger;
}

void Ticket::setFlight(Flight flight){
    this->flight = flight;
}

void Ticket::setStatus(string status){
    this->status = status;
}

void Ticket::setSeatNumber(int seatNumber){
    this->seatNumber = seatNumber;
}