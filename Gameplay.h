#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "Vehicle_Upgrade.h"
#include "Race.h"

//------------Tworzenie postaci i menu--------------------

void game();

class Game
{
    bool menu;
    int choice;
    string go;

    Driver Player;

    void display_menu();
    void do_race();

    public:

    void gameplay();

    Game(bool m = true, int c = 1, string g = "a");
    ~Game();
};

#endif
