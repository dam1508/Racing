#include "Vehicle_Upgrade.h"

void Workshop::set_costs()
{
    engine_cost = player.get_engine_power()*1500;
    acceleration_cost = player.get_acceleration()*1200;
}

void Workshop::display_menu()
{
    system("clear");
    player.display_player();

    cout<<"Co chcesz ulepszyć?:"<<endl;
    cout<<"1. Silnik - "<<engine_cost<<"$$$"<<endl;
    cout<<"2. Skrzynia biegow - "<<acceleration_cost<<"$$$"<<endl;
    cout<<"3. Wyjdz"<<endl;
}

void Workshop::upgrade_engine()
{
    if(player.get_money() >= engine_cost)
    {
        player.spend(engine_cost);
        player.upgrade_engine();
    }else{
        cout<<"Brak srodkow"<<endl;
    }
}

void Workshop::upgrade_acceleration()
{
    if(player.get_money() >= acceleration_cost)
    {
        player.spend(acceleration_cost);
        player.upgrade_acceleration();
    }else{
        cout<<"Brak srodkow"<<endl;
    }
}

void Workshop::modify_car()
{

    while(menu==true)
    {
        set_costs();
        display_menu();
        limited_int_cin(choice, 1, 3);

        switch(choice)
        {
            case 1:
                upgrade_engine();
            break;

            case 2:
                upgrade_acceleration();
            break;

            case 3:
                menu=false;
            break;
        }
    }
}

Workshop::Workshop(Driver d, bool m, int c, int ec, int ac) :player(d)
{
    menu = m;
    choice = c;
}

Workshop::~Workshop()
{

}
