#ifndef RACE_H
#define RACE_H
#include "Driver.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

class Driver;

class Race
{
    int number_of_drivers;
    double length;
    double turns_per_500;
    int difficulty;
    int winning_prize;
    int participation_prize;
    Driver *drivers;

    Driver generate_driver();

    public:

    void generate_drivers(Driver player);
    void display_drivers();
    void set_driver_score(Driver &driver);
    int race(Driver player);
    void display_scores(Driver player);
    Driver rewards(int win);

    Race(int nod=4, int l=1000, double tp500=1.75, int d=100, int wp=10000, int pp=1000);
    ~Race();
};

#endif
