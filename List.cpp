#include "List.h"

Driver_Node::Driver_Node(int p)    :driver(1, 1, 1, 1, 0, 1, 0, 0, 0, "mark")
{
    place = p;
    next = NULL;
}

Driver_Node::~Driver_Node()
{
}

void Driver_List::add_driver(Driver add_this_driver)
{
        Driver_Node *node;
        node = new Driver_Node(0);
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
