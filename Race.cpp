#include "Race.h"
#include "Functions.h"

Driver Race::generate_driver(int min_lvl, int max_lvl)
{
    Driver d(random_number(min_lvl, max_lvl),random_number(min_lvl, max_lvl),random_number(min_lvl, max_lvl),random_number(min_lvl, max_lvl));
    return d;
}

void Race::generate_drivers(Driver player)
{
    drivers = new Driver[number_of_drivers];

    drivers[0]=player;

    for(int i=1;i<number_of_drivers;++i)
    {
        drivers[i]=generate_driver(2, 6);
    }
}

void Race::display_drivers()
{
    for(int i=0;i<number_of_drivers;++i)
    {
        cout<<i<<". ";
        drivers[i].display_stats();
        cout<<endl<<endl;
    }
}

void Race::display_race()
{
    cout<<"*****WYSCIG*****"<<endl;
    cout<<"Liczba zawodnikow: "<<number_of_drivers<<endl;
    cout<<"Dlugosc trasy: "<<length<<" m"<<turns_per_500<<endl;
    cout<<"Poziom trudnosci: "<<difficulty<<"%"<<endl;
    cout<<"Nagroda za wygrana: "<<winning_prize<<"$$$"<<endl;
    cout<<"Pieniadze za udzial: "<<participation_prize<<"$$$"<<endl;
    cout<<"****************"<<endl;
    display_drivers();

}

void Race::set_driver_score(Driver &driver)
{
    double perception_skill_adjustment; perception_skill_adjustment=double(70+10*driver.perception)/100;
    double handling_skill_adjustment;   handling_skill_adjustment=double(70+10*driver.handling)/100;
    double speed_score;                 speed_score=(length/500)*driver.engine_power;
    double maneuver_score;              maneuver_score=((length/500)*turns_per_500)*driver.acceleration/2;

    driver.race_score = speed_score*perception_skill_adjustment + maneuver_score*handling_skill_adjustment;
}

int Race::race(Driver player)
{
    for(int i=0;i<number_of_drivers;++i)
    {
        set_driver_score(drivers[i]);
    }

    int winner=0;

    for(int i=1;i<number_of_drivers;++i)
    {
        if(drivers[winner].race_score<drivers[i].race_score)
            winner=i;
    }

    return winner;
}

void Race::display_scores(Driver player)
{
    cout<<"Twoj wynik: ";
    /*player.display_score();*/drivers[0].display_score(); cout<<endl<<endl;
    cout<<"Wyniki przeciwnikow:"<<endl<<endl;

    for(int i=1;i<number_of_drivers;++i)
    {
        cout<<i<<". ";
        drivers[i].display_score();
        cout<<endl;
    }
}

Driver Race::rewards(int win)
{
    if(win==0)  drivers[0].money+=winning_prize;
    else        drivers[0].money+=participation_prize;

    if(win==0)  drivers[0].level_up((length*(double)difficulty/100)*2.5);
    else        drivers[0].level_up(length*(double)difficulty/100);

    return drivers[0];
}

Race::Race(int nod, int l, double tp500, int d, int wp, int pp)
{
    number_of_drivers=nod;
    length=l;
    turns_per_500=tp500;
    difficulty=d;
    winning_prize=wp;
    participation_prize=pp;
}

Race::~Race()
{
    delete[] drivers;
}
