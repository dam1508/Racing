#include "Race.h"
#include "Functions.h"

using namespace std;

Driver Race::generate_driver()

{//srand(time(NULL));
    Driver d(random_number(1,10),random_number(1,10),random_number(1,10),random_number(1,10));

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
