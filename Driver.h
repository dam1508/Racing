#ifndef DRIVER_H
#define DRIVER_H
#include <iostream>
#include "Vehicle.h"

using namespace std;

class Driver :public Vehicle
{
    //string name;
    int handling;
    int perception;

    public:

        void display_stats();

        Driver(int h=1 ,int p=1, int v_ep=1, int v_a=1);
        ~Driver();

};

#endif
