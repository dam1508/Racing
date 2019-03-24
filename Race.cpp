#include <iostream>
#include "Race.h"

using namespace std;

Driver Race::generate_driver()

{
    Driver d(1,2,3,4);

    return d;
}

void Race::generate_drivers()
{
    drivers = new Driver[number_of_drivers];

    for(int i=0;i<number_of_drivers;++i)
    {
        drivers[i]=generate_driver();
    }
}

void Race::display_drivers()
{
    for(int i=0;i<number_of_drivers;++i)
    {
        cout<<i+1<<". ";
        drivers[i].display_stats();
        cout<<endl<<endl;
    }
}

Race::Race(int nod, int l, int tp250)
{
    number_of_drivers=nod;
    length=l;
    turns_per_250=tp250;
}

Race::~Race()
{

}
