#ifndef LIST_H
#define LIST_H
#include "List_Element.h"

//-------------------------RZECZY POTRZEBNE DO LISTY---------------------------



class Driver_List
{
    public:

    Driver_Node *beggining;

    void add_driver(Driver add_this_driver);

    Driver_List();
    ~Driver_List();
};

#endif
