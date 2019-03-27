#include <ctime>
#include <iostream>
#include "Driver.h"
#include "Race.h"
#include "Functions.h"
#include "Vehicle_Upgrade.h"
#include "Gameplay.h"

using namespace std;

int main()
{
    srand(time(NULL));
    game();
    /*Driver d(10,10,10,10,0,20,0,10,10,"xddd");
    Race race;
    race.generate_drivers(d);
    race.display_race();*/
}
