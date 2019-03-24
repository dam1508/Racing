#include "Driver.h"

void Driver::level_up(int exp)
{
    experience+=exp;

    if(experience>mastery_lvl*2500)
    {
        experience-=mastery_lvl*2500;
        ++mastery_lvl;
    }
}

void Driver::display_stats()
{
    cout<<"Prowadzenie: "<<handling<<endl<<"Percepcja: "<<perception<<endl;
    cout<<"Statystyki samochodu:"<<endl;
    Vehicle::display_statistics();
}
void Driver::display_player()
{
    cout<<"-------------------------------------"<<endl;
    cout<<name<<"\tLvl: "<<mastery_lvl<<"\t$$$: "<<money<<endl<<endl;
    cout<<"Prowadzenie: "<<handling<<endl<<"Percepcja: "<<perception<<endl<<endl;
    cout<<"Statystyki samochodu:"<<endl<<endl;
    Vehicle::display_statistics();  cout<<endl;
    cout<<"-------------------------------------"<<endl;
}

void Driver::display_score()
{
    cout<<race_score;
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
