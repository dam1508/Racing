#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits>

using namespace std;

int random_number(int minimum, int maximum);
double random_double(int minimum, int maximum, int accuracy);

void safe_int_cin(int &number);                                 //bezpieczne wczytywanie int
void limited_int_cin(int &number, int minimum, int maximum);    //bezpieczne i ograniczone wpisywanie int

#endif
