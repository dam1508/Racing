#ifndef LIST_H
#define LIST_H
#include "Driver.h"

//-------------------------RZECZY POTRZEBNE DO LISTY---------------------------

class Driver;
class Driver_List;

class Driver_Node
{
    protected:

    Driver driver;
    Driver_Node *next;
    int place;

    public:

    int get_place() const {return place;}
    Driver get_driver() const {return driver;}
    Driver_Node* get_next() const {return next;}

    void set_driver(Driver new_driver) {driver = new_driver;}
    void set_next(Driver_Node *nxt) {next = nxt;}
    void set_place(int plc) {place = plc;}

    Driver_Node();
    ~Driver_Node();
};

class Driver_List
{
    public:

    Driver_Node *beggining;

    void add_driver(Driver add_this_driver);

    Driver_List();
    ~Driver_List();
};

#endif
