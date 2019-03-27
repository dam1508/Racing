#ifndef DRIVER_H
#define DRIVER_H
#include "Vehicle.h"
#include "Race.h"
#include "Gameplay.h"
#include <string>

class Race;
class Vehicle_Upgrade;
class Game;

//-------------------------KLASA KIEROWCY---------------------------

class Driver :public Vehicle
{
    friend class Race;
    friend class Vehicle_Upgrade;

    string name;
    int experience;
    int mastery_lvl;
    int skill_points;
    int handling;
    int perception;
    int money;
    double race_score;

    void level_up(int exp);
    void spend_skill_points();              //funkcja pozwalajaca ulepszac statystyki kierowcy za punkty umiejetnosci
    void display_stats();
    void display_player();
    void display_score();

    public:

    const Driver& operator=(const Driver& driver);

    Driver(int h=1 ,int p=1, int v_ep=1, int v_a=1,int e=0,int lvl=1,int sp=0, int mn=0, double rs=0, string n="Mark");
    ~Driver();

    friend void workshop(Driver &player);
    friend void game();
};

//-------------------------RZECZY POTRZEBNE DO LISTY---------------------------

struct Driver_Node
{
    Driver driver;
    Driver_Node *next;
    Driver_Node *previous;

    public:

    int place = 0;
};

class Driver_List
{
    public:

    Driver_Node *beggining;

    void add_driver(Driver add_this_driver);

    Driver_List();
    ~Driver_List();
};

#endif
