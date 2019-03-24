#ifndef DRIVER_H
#define DRIVER_H
#include "Vehicle.h"
#include "Race.h"
#include "Vehicle_Upgrade.h"
#include <string>

class Race;
class Vehicle_Upgrade;

class Driver :public Vehicle
{
    friend class Race;
    friend class Vehicle_Upgrade;

    string name;
    int experience;
    int mastery_lvl;
    int handling;
    int perception;
    int money;
    double race_score;

    public:

    void level_up(int exp);
    void display_stats();
    void display_player();
    void display_score();

    Driver(int h=1 ,int p=1, int v_ep=1, int v_a=1,int e=0,int lvl=1, int mn=0, double rs=0, string n="Mark");
    ~Driver();

    friend void workshop(Driver &player);
    //friend void Race::set_driver_score(Driver driver);

};

#endif
