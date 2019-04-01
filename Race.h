#ifndef RACE_H
#define RACE_H
#include "List.h"
#include "Functions.h"
#include <cstdlib>

//------------------KLASA WYSCIGU-------------------

class Race :public Driver_List
{
    int number_of_drivers;
    double length;
    double turns_per_500;
    int difficulty;
    int winning_prize;
    int participation_prize;

    void display_drivers();
    Driver generate_driver(int min_lvl, int max_lvl);
    void generate_drivers(Driver player);
    void display_race();
    double driver_score(Driver driver);

    public:

    void race(Driver player);
    void display_scores();
    void rewards(Driver &player);

    Race(int nod=4, int l=1000, double tp500=1.75, int d=100, int wp=10000, int pp=1000);
    ~Race();
};

#endif
