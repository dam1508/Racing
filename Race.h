#ifndef RACE_H
#define RACE_H
#include <iostream>
#include "Driver.h"

using namespace std;

class Race :public Driver
{
    int number_of_drivers;
    double length;
    double turns_per_250;
    Driver *drivers;

    Race::Driver generate_driver();

    public:

    void generate_drivers();
    void display_drivers();

    Race(int nod=2, int l=1000, int tp250=1);
    ~Race();
};

#endif
