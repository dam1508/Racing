#ifndef VEHICLE_UPGRADE_H
#define VEHICLE_UPGRADE_H
#include "Driver.h"
#include "Functions.h"

class Driver;

//------------Funkcja pozwalajaca ulepszyc pojazd za pieniadze----------------

class Workshop
{
    Driver player;
    bool menu;
    int choice;
    int engine_cost;
    int acceleration_cost;

    void set_costs();
    void display_menu();
    void upgrade_engine();
    void upgrade_acceleration();

    public:

    Driver get_driver() const {return player;}

    void set_driver(Driver driver) {player = driver;}

    void modify_car();

    Workshop(Driver p, bool m = true, int c = 1, int ec = 0, int ac = 0);
    ~Workshop();
};

#endif
