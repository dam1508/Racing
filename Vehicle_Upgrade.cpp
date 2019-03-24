#include "Vehicle_Upgrade.h"

void workshop(Driver &player)
{
    int eng_cost;
    int acc_cost;

    bool menu=true;
    int choice;

    while(menu==true)
    {
        eng_cost=player.engine_power*1500;
        acc_cost=player.acceleration*1200;

        system("clear");
        player.display_player();

        cout<<"Co chcesz ulepszyć?:"<<endl;
        cout<<"1. Silnik - "<<eng_cost<<"$$$"<<endl;
        cout<<"2. Skrzynia biegow - "<<acc_cost<<"$$$"<<endl;
        cout<<"3. Wyjdz"<<endl;
        limited_int_cin(choice, 1, 3);

        switch(choice)
        {
            case 1:
            {
                if(player.money>=eng_cost)
                {
                    player.money-=eng_cost;
                    ++player.engine_power;
                }else{
                    cout<<"Brak srodkow"<<endl;
                }
            }
            break;

            case 2:
            {
                if(player.money>=acc_cost)
                {
                    player.money-=acc_cost;
                    ++player.acceleration;
                }else{
                    cout<<"Brak srodkow";
                }
            }
            break;

            case 3:
                menu=false;
            break;
        }
    }
}
