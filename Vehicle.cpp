#include "Vehicle.h"

using namespace std;

void Vehicle::display_statistics()
{
    cout<<"Moc silnika: "<<engine_power<<endl<<"Przyspieszenie: "<<acceleration;
}

Vehicle::Vehicle(int ep ,int acc)
{
    engine_power=ep;
    acceleration=acc;
}

Vehicle::~Vehicle()
{

}
