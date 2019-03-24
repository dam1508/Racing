#include <ctime>
#include <iostream>
#include "Driver.h"
#include "Race.h"
#include "Functions.h"
#include "Vehicle_Upgrade.h"
#include "Gameplay.h"

using namespace std;

int main()
{srand(time(NULL));
    /*srand(time(NULL)); Driver d1(6,9,1,2);
for(int i=0;i<3;++i){
    d1.display_player();
    Race r1;
    d1=r1.rewards(r1.race(d1));
    r1.display_drivers();
    d1.display_player();}


    workshop(d1);*/
    game();

}
