#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>

using namespace std;

class Vehicle
{
    protected:

    int engine_power;
    int acceleration;

    public:
        void display_statistics();

        Vehicle(int ep=1, int acc=1);
        ~Vehicle();
};

#endif // VEHICLE_H
