#include "Race.h"
#include "Functions.h"

Driver Race::generate_driver()
{
    Driver d(random_number(1,10),random_number(1,10),random_number(1,10),random_number(1,10));
    return d;
}

void Race::generate_drivers(Driver player)
{
    drivers = new Driver[number_of_drivers];

    drivers[0]=player;

    for(int i=1;i<number_of_drivers;++i)
    {
        drivers[i]=generate_driver();
    }
}

void Race::display_drivers()
{
    for(int i=1;i<number_of_drivers;++i)
    {
        cout<<i<<". ";
        drivers[i].display_stats();
        cout<<endl<<endl;
    }
}

void Race::set_driver_score(Driver &driver)
{
    driver.race_score=(length/500)*driver.engine_power+((length/250)*turns_per_500)*driver.acceleration/2;
}

int Race::race(Driver player)
{
    //generate_drivers(player);

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
    player.display_score(); cout<<endl<<endl;
    cout<<"Wyniki przeciwnikow:"<<endl;

    for(int i=1;i<number_of_drivers;++i)
    {
        cout<<i<<". ";
        drivers[i].display_score();
        cout<<endl<<endl;
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
