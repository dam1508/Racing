#include <ctime>
//#include "Vehicle.h"
#include "Driver.h"
#include "Race.h"

using namespace std;

int main()
{
    srand(time(NULL)); Driver d1(6,9,10,10);
for(int i=0;i<3;++i){
    d1.display_player();
    Race r1;
    d1=r1.rewards(r1.race(d1));
    r1.display_drivers();
    d1.display_player();}
}
