#include "Race.h"
#include "Functions.h"

Driver Race::generate_driver(int min_lvl, int max_lvl)
{
    Driver d(random_number(min_lvl, max_lvl),random_number(min_lvl, max_lvl),random_number(min_lvl, max_lvl),random_number(min_lvl, max_lvl));
    return d;
}

void Race::generate_drivers(Driver player)
{
    drivers = new Driver_List;

    for(int i=1;i<number_of_drivers;++i)
    {
        drivers->add_driver(generate_driver(1,10));
        drivers->beggining->place = 0;
    }

    drivers->add_driver(player);
}

void Race::display_drivers()
{
    Driver_Node *help;
    help = drivers->beggining;
    help = help->next;

    cout<<"Przeciwnicy: "<<endl;

    for(int i=1;i<number_of_drivers;++i)
    {
        cout<<i<<". ";
        help->driver.display_stats();
        cout<<endl<<endl;
        help=help->next;
    }
}

void Race::display_race()
{
    cout<<"*****WYSCIG*****"<<endl;
    cout<<"Liczba zawodnikow: "<<number_of_drivers<<endl;
    cout<<"Dlugosc trasy: "<<length<<" m"<<turns_per_500<<endl;
    cout<<"Poziom trudnosci: "<<difficulty<<"%"<<endl;
    cout<<"Nagroda za wygrana: "<<winning_prize<<"$$$"<<endl;
    cout<<"Pieniadze za udzial: "<<participation_prize<<"$$$"<<endl;
    cout<<"****************"<<endl;
    display_drivers();

}

void Race::set_driver_score(Driver &driver)
{
    double perception_skill_adjustment; perception_skill_adjustment=double(70+10*driver.perception)/100;
    double handling_skill_adjustment;   handling_skill_adjustment=double(70+10*driver.handling)/100;
    double speed_score;                 speed_score=(length/500)*driver.engine_power;
    double maneuver_score;              maneuver_score=((length/500)*turns_per_500)*driver.acceleration/2;

    driver.race_score = speed_score*perception_skill_adjustment + maneuver_score*handling_skill_adjustment;
}

void Race::race()
{
    Driver_Node *help;
    help=drivers->beggining;

    for(int i=0;i<number_of_drivers;++i)
    {
        set_driver_score(help->driver);
        help = help->next;
    }

    double max_score;              max_score = 0;
    double previous_max_score;     previous_max_score = 0;
    int max_id;
    bool done;  done = false;

    for(int i=0;i<number_of_drivers;++i)
    {
        help = drivers->beggining;

        for(int j=0;j<number_of_drivers;++j)
        {
            if(done == false)
            {
                if(max_score < help->driver.race_score)
                {
                    max_score = help->driver.race_score;
                    max_id = j;
                }
            }else{

                if(previous_max_score > help->driver.race_score && max_score < help->driver.race_score)
                {
                    max_score = help->driver.race_score;
                    max_id = j;
                }
            }
            help = help->next;
        }
        help = drivers->beggining;
        for(int k=0;k<max_id;++k)
        {
            help = help->next;
        }help->place=i+1;

        previous_max_score = max_score;
        max_score = 0;
        done = true;
    }
}

void Race::display_scores()
{
    Driver_Node *help;
    help = drivers->beggining;

    cout<<"Twoj wynik: ";
    help->driver.display_score(); cout<<" Miejsce: "<<help->place<<endl<<endl;
    help = help->next;

    cout<<"Wyniki przeciwnikow:"<<endl<<endl;

    for(int i=1;i<number_of_drivers;++i)
    {
        cout<<i<<". ";
        help->driver.display_score();
        cout<<" Miejsce: "<<help->place<<endl;
        help = help->next;
    }
}

void Race::rewards(Driver &player)
{
    if(drivers->beggining->place==1)
        drivers->beggining->driver.money += winning_prize;

    if(drivers->beggining->place==2)
        drivers->beggining->driver.money += winning_prize/2;

    if(drivers->beggining->place==3)
        drivers->beggining->driver.money += winning_prize/4;

    drivers->beggining->driver.money += participation_prize;

    int exp; exp = length*(double)difficulty/100;

    drivers->beggining->driver.level_up(exp);

    player=drivers->beggining->driver;
}

Race::Race(int nod, int l, double tp500, int d, int wp, int pp)
{
    number_of_drivers=nod;
    length=l;
    turns_per_500=tp500;
    difficulty=d;
    winning_prize=wp;
    participation_prize=pp;
}

Race::~Race()
{
    delete drivers;
}
