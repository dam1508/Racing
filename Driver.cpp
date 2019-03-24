#include "Driver.h"

using namespace std;

void Driver::display_stats()
{
    cout<<"Prowadzenie: "<<handling<<endl<<"Percepcja: "<<perception<<endl;
    cout<<"Statystyki samochodu:"<<endl;
    Vehicle::display_statistics();
}

Driver::Driver(int h, int p, int v_ep, int v_a)
    :Vehicle(v_ep,v_a)
{
    handling=h;
    perception=p;
}

Driver::~Driver()
{

}
