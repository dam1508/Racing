#ifndef LIST_ELEMENT_H
#define LIST_ELEMENT_H
#include "Driver.h"

class Driver_Node
{
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

    Driver_Node(int p = 0);
    ~Driver_Node();
};

#endif
