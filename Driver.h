#ifndef DRIVER_H
#define DRIVER_H
#include "Vehicle.h"
#include "Functions.h"
#include <string>

class Vehicle_Upgrade;
class Game;
class Race;

//-------------------------KLASA KIEROWCY---------------------------

class Driver :public Vehicle
{
    string name;
    int experience;
    int mastery_lvl;
    int skill_points;
    int money;
    double race_score;

    //protected:

    int handling;
    int perception;

    public:

    int get_handling() const {return handling;}
    int get_perception() const {return perception;}
    int get_engine_power() const {return engine_power;}
    int get_acceleration() const {return acceleration;}
    int get_money() const {return money;}
    double get_race_score() const {return race_score;}

    void set_score(double new_score) {race_score = new_score;}

    void upgrade_engine() {++engine_power;}
    void upgrade_acceleration() {++acceleration;}
    void choose_name();
    void profit(int cash);
    void spend(int cash);
    void level_up(int exp);
    void spend_skill_points();              //funkcja pozwalajaca ulepszac statystyki kierowcy za punkty umiejetnosci

    void display_player();
    void display_score();
    void display_stats();

    const Driver& operator=(const Driver& driver);

    Driver(int h=1 ,int p=1, int v_ep=1, int v_a=1,int e=0,int lvl=1,int sp=0, int mn=0, double rs=0, string n="Mark");
    ~Driver();

    friend void workshop(Driver &player);
};

#endif
