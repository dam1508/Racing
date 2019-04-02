#include "List.h"

void Driver_List::add_driver(Driver add_this_driver)
{
        Driver_Node *node;
        node = new Driver_Node;
        node->set_driver(add_this_driver);
        node->set_next(beggining);
        beggining=node;
}

Driver_List::Driver_List()
{
    beggining=NULL;
}

Driver_List::~Driver_List()
{
    Driver_Node *help;
    help = beggining;
    while(help)
    {
        beggining = beggining->get_next();
        delete help;
        help = beggining;
    }
}
