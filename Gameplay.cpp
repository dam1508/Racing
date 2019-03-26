#include "Gameplay.h"

void game()
{
    int menu=true;
    int choice;
    string go;
    int winner;

    string player_name;
    cout<<"Tworzenie nowego gracza"<<endl;
    cout<<"Podaj nazwe: ";  cin>>player_name;
    Driver Player(1, 1, 1, 1, 0, 1, 0, 0, 0, player_name);

    while(menu==true)
    {
        system("clear");
        Player.display_player();
        cout<<"1. Wyscigi"<<endl;
        cout<<"2. Ulepsz umiejetnosci"<<endl;
        cout<<"3. Warsztat"<<endl;
        cout<<"4. Wyjdz"<<endl;
        limited_int_cin(choice, 1, 4);

        switch(choice)
        {
            case 1:
            {
                Race race(random_number(5, 20), random_double(750, 3500, 0), random_double(1, 4, 2), random_number(40, 200), random_number(5,20)*1000, random_number(4,15)*100);
                race.generate_drivers(Player);
                system("clear");
                cout<<"Przeciwnicy: "<<endl;
                race.display_race();
                cin>>go;

                winner=race.race(Player);
                system("clear");
                if(winner==0)   cout<<"!!!WYGRANA!!!"<<endl<<endl;
                else            cout<<"PRZEGRANA"<<endl<<endl;
                race.display_scores(Player);
                cin>>go;

                Player=race.rewards(winner);
                break;
            }

            case 2:
                Player.spend_skill_points();
            break;

            case 3:
                workshop(Player);
            break;

            case 4:
                menu=false;
            break;
        }


    }
}
