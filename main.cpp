#include <iostream>
//#include "Vehicle.h"
#include "Driver.h"
#include "Race.h"

using namespace std;

int main()
{
    Race r1;

    r1.generate_drivers();

    r1.display_drivers();
}
