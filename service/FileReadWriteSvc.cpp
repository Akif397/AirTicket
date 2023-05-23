#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "FileReadWriteSvc.h"
#include "..\model\Passenger.h"
#include "..\model\Flight.h"
#include "..\model\Ticket.h"

using namespace std;

void FileReadWriteSvc::writePassengerInformation(Passenger passenger)
{
    ofstream myfile;
    myfile.open("Passenger.txt");
    myfile << passenger.getEmail() + " " + passenger.getName() + " " + passenger.getPassword() + "\n";
    myfile.close();
}

void FileReadWriteSvc::writeFlightInformation()
{
    ofstream myfile;
    myfile.open("Flight.txt");

    string airports[100] = {"Vienna", "Helsinki-Vantaa", "Rome", "Copenhagen", "Kansai", "Centrair-Nagoya", "Dubai", "Seattle-Tacoma", "Melbourne", "Vancouver", "Dusseldorf", "London Heathrow", "Brisbane", "Guangzhou", "Frankfurt", "Bahrain", "Riyadh", "Haikou-Meilan", "Amsterdam", "Fukuoka", "Shenzhen", "Houston", "Hong-Kong", "Barcelona", "Houston-George-Bush", "Delhi", "Bogota", "Hamburg", "Paris-Orly", "Quito", "Jeddah", "Muscat", "Jakarta", "Dammam", "Montréal", "Cincinnati-Northern-Kentucky", "Cape-Town", "San-Francisco", "Sydney", "Shanghai-Hongqiao", "Auckland", "Medina", "Baku", "Gold-Coast", "London Gatwick", "Cologne-Bonn", "New-York-LGA", "Perth", "Chengdu-Tianfu", "Athens", "Durban-King-Shaka", "Atlanta", "Los-Angeles", "Toronto-Pearson", "Hyderabad", "Dallas-Fort-Worth", "Kuala-Lumpur", "Bangkok Suvarnabhumi", "Bangalore", "London-City", "Denver", "Xi'an", "Adelaide", "Seoul-Gimpo", "Johannesburg", "Oslo", "Budapest", "Málaga", "Malta", "Denpasar-Bali", "Porto", "Taiwan-Taoyuan", "Lisbon", "Mumbai", "Stockholm-Arlanda", "Milan-Malpensa", "Abu-Dhabi", "New-York-JFK", "Lima", "Alicante", "Palma-de-Mallorca", "Calgary", "Keflavik", "Phoenix", "Osaka-Itami", "Boston-Logan", "Changsha", "Lyon", "Minneapolis-St.Paul", "Christchurch", "Singapore-Changi", "Doha-Hamad", "Tokyo-Haneda", "Seoul-Incheon", "Paris-CDG", "Istanbul", "Munich", "Zurich", "Tokyo-Narita", "Madrid-Barajas"};
    srand(time(0));
    string data = "";
    for (int i = 0; i < 100; i++)
    {
        Flight flight;
        int firstD = rand() % 2;
        int secondD = rand() % 9;
        int thirdD = rand() % 6;
        int fourthD = rand() % 9;

        string time = to_string(firstD) + to_string(secondD) + to_string(thirdD) + to_string(fourthD);

        flight.setId(i + 1);
        flight.setName("BA" + to_string(i));
        flight.setDeparture(airports[i]);
        flight.setDestination(airports[99 - i]);
        flight.setdeptTime(time);
        flight.setTotalSeat(100 + (rand() % 100));
        flight.setBusinessSeat(1 + (rand() % 30));
        flight.setEconSeat(flight.getTotalSeat() - flight.getBusinessSeat());

        data += to_string(flight.getId()) + " " + flight.getName() + " " + flight.getDeparture() + " " + flight.getDestination() + " " + flight.getDeptTime() + " " + to_string(flight.getTotalSeat()) + " " + to_string(flight.getBusinessSeat()) + " " + to_string(flight.getEconSeat()) + "\n";
    }
    myfile << data;
    myfile.close();
}

Passenger FileReadWriteSvc::matchPassengerInformation(Passenger passenger)
{
    Passenger p;
    bool isCredentialMatch = false;
    string myText;
    ifstream MyReadFile("Passenger.txt");
    while (getline(MyReadFile, myText))
    {
        int currIndex = 0, i = 0, counter = 0;
        int startIndex = 0, endIndex = 0;
        while (i <= len(myText))
        {
            if (myText[i] == ' ' || i == len(myText))
            {
                endIndex = i;
                string subStr = "";
                subStr.append(myText, startIndex, endIndex - startIndex);
                if (counter == 0)
                {
                    if (subStr != passenger.getEmail())
                    {
                        break;
                    }
                    p.setEmail(subStr);
                }
                else if (counter == 1)
                {
                    p.setName(subStr);
                }
                else if (counter == 2)
                {
                    p.setName(p.getName() + " " + subStr);
                }
                else if (counter == 3)
                {
                    if (subStr == passenger.getPassword())
                    {
                        p.setPassword(subStr);
                        isCredentialMatch = true;
                    }
                    break;
                }
                currIndex += 1;
                startIndex = endIndex + 1;
                counter++;
            }
            i++;
        }
        if (isCredentialMatch)
        {
            break;
        }
    }
    if (!isCredentialMatch)
    {
        Passenger *nullPassenger = &p;
        nullPassenger = NULL;
    }
    else
    {
        p.setIsLoggedIn(true);
    }
    return p;
}

Passenger FileReadWriteSvc::matchPassengerInformation(string email)
{
    Passenger p;
    bool isCredentialMatch = false;
    string myText;
    ifstream MyReadFile("Passenger.txt");
    while (getline(MyReadFile, myText))
    {
        int currIndex = 0, i = 0, counter = 0;
        int startIndex = 0, endIndex = 0;
        while (i <= len(myText))
        {
            if (myText[i] == ' ' || i == len(myText))
            {
                endIndex = i;
                string subStr = "";
                subStr.append(myText, startIndex, endIndex - startIndex);
                if (counter == 0)
                {
                    if (subStr != email)
                    {
                        break;
                    }
                    p.setEmail(subStr);
                    isCredentialMatch = true;
                }
                else if (counter == 1)
                {
                    p.setName(subStr);
                }
                else if (counter == 2)
                {
                    p.setName(p.getName() + " " + subStr);
                }
                else if (counter == 3)
                {
                    p.setPassword(subStr);
                }
                currIndex += 1;
                startIndex = endIndex + 1;
                counter++;
            }
            i++;
        }
        if (isCredentialMatch)
        {
            break;
        }
    }
    return p;
}

Ticket FileReadWriteSvc::readTicketInformation(int tktNo)
{
    Ticket tkt;
    string myText;
    int count = 0;
    ifstream MyReadFile("Ticket.txt");
    while (getline(MyReadFile, myText))
    {
        if (count == tktNo)
        {
            int currIndex = 0, i = 0, counter = 0;
            int startIndex = 0, endIndex = 0;
            while (i <= len(myText))
            {
                if (myText[i] == ' ' || i == len(myText))
                {
                    endIndex = i;
                    string subStr = "";
                    subStr.append(myText, startIndex, endIndex - startIndex);
                    if (counter == 0)
                    {
                        tkt.setId(stoi(subStr));
                    }
                    else if (counter == 1)
                    {
                        tkt.setPassenger(FileReadWriteSvc::matchPassengerInformation(subStr));
                    }
                    else if (counter == 2)
                    {
                        tkt.setFlight(FileReadWriteSvc::readFlightInformation(stoi(subStr) - 1));
                    }
                    else if (counter == 3)
                    {
                        tkt.setSeatNumber(stoi(subStr));
                    }
                    else if (counter == 4)
                    {
                        tkt.setStatus(subStr);
                    }
                    currIndex += 1;
                    startIndex = endIndex + 1;
                    counter++;
                }
                i++;
            }
            break;
        }
        count++;
    }
    MyReadFile.close();
    return tkt;
}

Flight FileReadWriteSvc::readFlightInformation(int flightNo)
{
    Flight flight;
    string myText;
    int count = 0;
    ifstream MyReadFile("Flight.txt");
    while (getline(MyReadFile, myText))
    {
        if (count == flightNo)
        {
            int currIndex = 0, i = 0, counter = 0;
            int startIndex = 0, endIndex = 0;
            while (i <= len(myText))
            {
                if (myText[i] == ' ' || i == len(myText))
                {
                    endIndex = i;
                    string subStr = "";
                    subStr.append(myText, startIndex, endIndex - startIndex);
                    if (counter == 0)
                    {
                        flight.setId(stoi(subStr));
                    }
                    else if (counter == 1)
                    {
                        flight.setName(subStr);
                    }
                    else if (counter == 2)
                    {
                        flight.setDeparture(subStr);
                    }
                    else if (counter == 3)
                    {
                        flight.setDestination(subStr);
                    }
                    else if (counter == 4)
                    {
                        flight.setdeptTime(subStr);
                    }
                    else if (counter == 5)
                    {
                        flight.setTotalSeat(stoi(subStr));
                    }
                    else if (counter == 6)
                    {
                        flight.setBusinessSeat(stoi(subStr));
                    }
                    else if (counter == 7)
                    {
                        flight.setEconSeat(stoi(subStr));
                    }
                    currIndex += 1;
                    startIndex = endIndex + 1;
                    counter++;
                }
                i++;
            }
            break;
        }
        count++;
    }
    MyReadFile.close();
    return flight;
}

int FileReadWriteSvc::len(string str)
{
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        length++;
    }
    return length;
}

int FileReadWriteSvc::getLineNo(string fileName)
{
    int number_of_lines = 0;
    string line;
    ifstream myfile(fileName);

    while (getline(myfile, line))
    {
        ++number_of_lines;
    }
    myfile.close();
    return number_of_lines;
}

void FileReadWriteSvc::writeTicketInformation(Ticket ticket)
{
    string data = "", fileName = "Ticket.txt";
    int totalLines = FileReadWriteSvc::getLineNo(fileName);
    ifstream readFile(fileName);
    for(int i = 0; i < totalLines; i++){
        Ticket tkt = FileReadWriteSvc::readTicketInformation(i);
        data += to_string(tkt.getId()) + " " + tkt.getPassenger().getEmail() + " " + to_string(tkt.getFlight().getId()) + " " + to_string(tkt.getSeatNumber()) + " " + tkt.getStatus() + "\n";
    }
    
    readFile.close();

    ofstream myfile;
    myfile.open(fileName);
    data += to_string(ticket.getId()) + " " + ticket.getPassenger().getEmail() + " " + to_string(ticket.getFlight().getId()) + " " + to_string(ticket.getSeatNumber()) + " " + ticket.getStatus() + "\n";
    myfile << data;
    myfile.close();
}

void FileReadWriteSvc::updateFlightTotalSeat(Flight flight, int seat)
{
    int totalFlights = FileReadWriteSvc::getLineNo("Flight.txt");
    string data = "";
    Flight oldFlight;
    for (int i = 0; i < totalFlights; i++)
    {
        if (i == flight.getId() - 1)
        {
            oldFlight = FileReadWriteSvc::readFlightInformation(i);
            oldFlight.setTotalSeat(oldFlight.getTotalSeat() - seat);
        }
        else
        {
            oldFlight = FileReadWriteSvc::readFlightInformation(i);
        }

        data += to_string(oldFlight.getId()) + " " + oldFlight.getName() + " " + oldFlight.getDeparture() + " " + oldFlight.getDestination() + " " + oldFlight.getDeptTime() + " " + to_string(oldFlight.getTotalSeat()) + " " + to_string(oldFlight.getBusinessSeat()) + " " + to_string(oldFlight.getEconSeat()) + "\n";
    }
    ofstream myfile;
    myfile.open("Flight.txt");
    myfile << data;
    myfile.close();
}
