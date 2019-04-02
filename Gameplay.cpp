#include "Gameplay.h"

void Game::display_menu()
{
    system("clear");
        Player.display_player();
        cout<<"1. Wyscigi"<<endl;
        cout<<"2. Ulepsz umiejetnosci"<<endl;
        cout<<"3. Warsztat"<<endl;
        cout<<"4. Wyjdz"<<endl;
}

void Game::do_race()
{
    Race race(random_number(5, 20), random_double(750, 3500, 0), random_double(1, 4, 2), random_number(40, 200), random_number(5,20)*1000, random_number(4,15)*100);

    race.race(Player);
    system("clear");
    if(race.beggining->get_place() == 1)   cout<<"!!!WYGRANA!!!"<<endl<<endl;
    else            cout<<"PRZEGRANA"<<endl<<endl;
    race.display_scores();
    cin>>go;

    race.rewards(Player);
}

void Game::gameplay()
{
    Player.choose_name();

    while(menu == true)
    {
        display_menu();
        limited_int_cin(choice, 1, 4);

        switch(choice)
        {
            case 1:
                do_race();
            break;

            case 2:
                Player.spend_skill_points();
            break;

            case 3:
            {

                Workshop w1(Player);
                w1.modify_car();
                Player = w1.get_driver();

            break;
            }
            case 4:
                menu = false;
            break;
        }
    }
}

Game::Game(bool m, int  c, string g) :Player(1, 1, 1, 1, 0, 1, 0, 0, 0, "mark")
{
    menu = m;
    choice = c;
    go = g;
}

Game::~Game()
{

}
