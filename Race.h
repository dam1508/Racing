#ifndef RACE_H
#define RACE_H
#include "List.h"
#include "Functions.h"
#include <cstdlib>

//class Driver;

//------------------KLASA WYSCIGU-------------------

class Race :public Driver_List
{
    //friend Driver_List;

    int number_of_drivers;
    double length;
    double turns_per_500;
    int difficulty;
    int winning_prize;
    int participation_prize;
    //Driver_List *drivers;       //Lista zawodnikow na dany wyscig

    void display_drivers();
    Driver generate_driver(int min_lvl, int max_lvl);
    void display_scores();
    void generate_drivers(Driver player);
    void display_race();
    double driver_score(Driver driver);
    void race();
    void rewards(Driver &player);

    public:

    Race(int nod=4, int l=1000, double tp500=1.75, int d=100, int wp=10000, int pp=1000);
    ~Race();

    friend void game();
};

#endif
