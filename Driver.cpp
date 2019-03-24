#include "Driver.h"

using namespace std;

void Driver::display_stats()
{
    cout<<"Prowadzenie: "<<handling<<endl<<"Percepcja: "<<perception<<endl;
    cout<<"Statystyki samochodu:"<<endl;
    Vehicle::display_statistics();
    cout<<endl<<"Wynik: "<<race_score<<endl;
}
void Driver::display_player()
{
    cout<<"-------------------------------------"<<endl<<"Prowadzenie: "<<handling<<endl<<"Percepcja: "<<perception<<endl;
    cout<<"Statystyki samochodu:"<<endl;
    Vehicle::display_statistics();
    cout<<endl<<"Wynik: "<<race_score<<endl<<"$$$: "<<money<<endl<<"-------------------------------------"<<endl;
}

Driver::Driver(int h, int p, int v_ep, int v_a,int e,int lvl, int m, double rs, string n)
    :Vehicle(v_ep,v_a)
{
    handling=h;
    perception=p;
    experience=e;
    mastery_lvl=lvl;
    money=m;
    race_score=rs;
    name=n;
}

Driver::~Driver()
{

}
