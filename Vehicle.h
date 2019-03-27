#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>

using namespace std;

//-----------------PRZYKLADOWY MODEL FORMULY-------------------------

class Vehicle
{
    protected:

    int engine_power;
    int acceleration;

    void display_statistics();

    public:

    Vehicle(int ep=1, int acc=1);
    ~Vehicle();
};

#endif
