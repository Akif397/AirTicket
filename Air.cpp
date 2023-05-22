#include <iostream>
#include "Air.h"

using namespace std;

Air::Air(string name)
{

    this->name = name;
}

void Air::print()
{
    cout << "Hello form class Air." << endl;
    cout << Air::name << endl;
}

void print()
{
    cout << "Hello";
}