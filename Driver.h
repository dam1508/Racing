#ifndef DRIVER_H
#define DRIVER_H
#include "Vehicle.h"
#include "Race.h"
#include <string>

using namespace std;

class Race;

class Driver :public Vehicle
{
    friend class Race;

    string name;
    int experience;
    int mastery_lvl;
    int handling;
    int perception;
    int money;

    public:

    double race_score;
    void display_stats();
    void display_player();

    Driver(int h=1 ,int p=1, int v_ep=1, int v_a=1,int e=0,int lvl=1, int mn=0, double rs=0, string n="Mark");
    ~Driver();

    //friend void Race::set_driver_score(Driver driver);

};

#endif
