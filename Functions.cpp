#include "Functions.h"

using namespace std;

int random_number(int minimum, int maximum)
{
    return rand()%(maximum - minimum +1) + minimum;
}
