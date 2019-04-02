#include "Driver.h"

void Driver::level_up(int exp)
{
    experience += exp;

    if(experience>mastery_lvl*2500)
    {
        experience-=mastery_lvl*2500;
        ++skill_points;
        ++mastery_lvl;
    }
}

void Driver::profit(int cash)
{
    money += cash;
}

void Driver::spend(int cash)
{
    money -= cash;
}

void Driver::choose_name()
{
    string player_name;
    cout<<"Tworzenie nowego gracza"<<endl;
    cout<<"Podaj nazwe: ";  cin>>player_name;
    name = player_name;
}

void Driver::spend_skill_points()
{
    bool menu=true;
    int choice;

    while(menu==true)
    {
        system("clear");
        display_player();

        cout<<"Co chcesz ulepszyć?:"<<endl;
        cout<<"1. Prowadzenie"<<endl;
        cout<<"2. Percepcja"<<endl;
        cout<<"3. Wyjdz"<<endl;
        limited_int_cin(choice, 1, 3);

        switch(choice)
        {
            case 1:
            {
                if(skill_points>0)
                {
                    --skill_points;
                    ++handling;
                }else{
                    cout<<"Brak punktow umiejetnosci"<<endl;
                }
            }
            break;

            case 2:
            {
                if(skill_points>0)
                {
                    --skill_points;
                    ++perception;
                }else{
                    cout<<"Brak punktow umiejetnosci"<<endl;
                }
            }
            break;

            case 3:
                menu=false;
            break;
        }
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
    cout<<name<<"\tLvl: "<<mastery_lvl<<"\tPunkty umiejetnosci: "<<skill_points<<"\t$$$: "<<money<<endl<<endl;
    cout<<"Prowadzenie: "<<handling<<endl<<"Percepcja: "<<perception<<endl<<endl;
    cout<<"Statystyki samochodu:"<<endl<<endl;
    Vehicle::display_statistics();  cout<<endl;
    cout<<"-------------------------------------"<<endl;
}

void Driver::display_score()
{
    cout<<race_score;
}

const Driver& Driver::operator=(const Driver& driver)
{
    name=driver.name;
    experience=driver.experience;
    mastery_lvl=driver.mastery_lvl;
    skill_points=driver.skill_points;
    handling=driver.handling;
    perception=driver.perception;
    engine_power=driver.engine_power;
    acceleration=driver.acceleration;
    money=driver.money;
    race_score=driver.race_score;
}

Driver::Driver(int h, int p, int v_ep, int v_a, int e, int lvl, int sp, int m, double rs, string n)
    :Vehicle(v_ep,v_a)
{
    handling=h;
    perception=p;
    experience=e;
    mastery_lvl=lvl;
    skill_points=sp;
    money=m;
    race_score=rs;
    name=n;
}

Driver::~Driver()
{

}

//--------------------------------------------------------------


