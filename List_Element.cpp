#include "List_Element.h"

Driver_Node::Driver_Node(int p)    :driver(1, 1, 1, 1, 0, 1, 0, 0, 0, "mark")
{
    place = p;
    next = NULL;
}

Driver_Node::~Driver_Node()
{

}
