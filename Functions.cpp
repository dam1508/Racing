#include "Functions.h"

int random_number(int minimum, int maximum)
{
    return rand()%(maximum - minimum +1) + minimum;
}

double random_double(int minimum, int maximum, int accuracy)
{
    minimum*=pow(10,accuracy);

    maximum*=pow(10,accuracy);

    return (float)(rand()%( maximum - minimum + 1 ) + minimum)/pow(10,accuracy);
}

void safe_int_cin(int &number)
{
    while(!(cin>>number))
    {
        cout<<"Blad odczytu\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
}

void limited_int_cin(int &number, int minimum, int maximum)
{
    do{
        safe_int_cin(number);
    }while(number<minimum || number>maximum);
}
