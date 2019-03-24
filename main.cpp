#include <ctime>
//#include "Vehicle.h"
#include "Driver.h"
#include "Race.h"

using namespace std;

int main()
{
    srand(time(NULL));

    Race r1;

    r1.generate_drivers();

    r1.display_drivers();
}
