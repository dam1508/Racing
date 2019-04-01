#include "Race.h"

Driver Race::generate_driver(int min_lvl, int max_lvl)
{
    Driver d(random_number(min_lvl, max_lvl),random_number(min_lvl, max_lvl),random_number(min_lvl, max_lvl),random_number(min_lvl, max_lvl));
    return d;
}

void Race::generate_drivers(Driver player)
{
    //drivers = new Driver_List;

    for(int i=1;i<number_of_drivers;++i)
    {
        add_driver(generate_driver(1,10));                     //Zmieniajac liczby w nawiasie mozna zmienic poziom trudnosci
        //beggining->set_place(0);
    }

    add_driver(player);
}

void Race::display_drivers()
{
    Driver_Node *help;
    help = beggining;
    help = help->get_next();

    cout<<"Przeciwnicy: "<<endl;

    for(int i=1;i<number_of_drivers;++i)
    {
        cout<<i<<". ";
        help->get_driver().display_stats();
        cout<<endl<<endl;
        help=help->get_next();
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

double Race::driver_score(Driver driver)
{
    double perception_skill_adjustment; perception_skill_adjustment=double(70+10*driver.get_perception())/100;
    double handling_skill_adjustment;   handling_skill_adjustment=double(70+10*driver.get_handling())/100;
    double speed_score;                 speed_score=(length/500)*driver.get_engine_power();
    double maneuver_score;              maneuver_score=((length/500)*turns_per_500)*driver.get_acceleration()/2;

    double score;

    score = speed_score*perception_skill_adjustment + maneuver_score*handling_skill_adjustment;
    return score;
    //driver.set_race_score(score);
}

void Race::race()
{
    Driver_Node *help;
    help = beggining;

    Driver d;

    for(int i=0;i<number_of_drivers;++i)
    {
        d = help->get_driver();
        d.set_score(driver_score(d));
        help->set_driver(d);
        help = help->get_next();
    }

    double max_score;              max_score = 0;
    double previous_max_score;     previous_max_score = 0;
    int max_id;
    bool done;  done = false;

    for(int i=0;i<number_of_drivers;++i)
    {
        help = beggining;

        for(int j=0;j<number_of_drivers;++j)
        {
            if(done == false)
            {
                if(max_score < help->get_driver().get_race_score())
                {
                    max_score = help->get_driver().get_race_score();
                    max_id = j;
                }
            }else{

                if(previous_max_score > help->get_driver().get_race_score() && max_score < help->get_driver().get_race_score())
                {
                    max_score = help->get_driver().get_race_score();
                    max_id = j;
                }
            }
            help = help->get_next();
        }
        help = beggining;
        for(int k=0;k<max_id;++k)
        {
            help = help->get_next();
        }help->set_place(i+1);

        previous_max_score = max_score;
        max_score = 0;
        done = true;
    }
}

void Race::display_scores()
{
    Driver_Node *help;
    help = beggining;

    cout<<"Twoj wynik: ";
    help->get_driver().display_score(); cout<<" Miejsce: "<<help->get_place()<<endl<<endl;
    help = help->get_next();

    cout<<"Wyniki przeciwnikow:"<<endl<<endl;

    for(int i=1;i<number_of_drivers;++i)
    {
        cout<<i<<". ";
        help->get_driver().display_score();
        cout<<" Miejsce: "<<help->get_place()<<endl;
        help = help->get_next();
    }
}

void Race::rewards(Driver &player)
{
    int earnings;

    if(beggining->get_place()==1)
        earnings += winning_prize;

    if(beggining->get_place()==2)
        earnings += winning_prize/2;

    if(beggining->get_place()==3)
        earnings += winning_prize/4;

    earnings += participation_prize;

    player.profit(earnings);

    int exp; exp = length*(double)difficulty/100;

    player.level_up(exp);
}

Race::Race(int nod, int l, double tp500, int d, int wp, int pp)
    :Driver_List()
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
    //delete drivers;
}
