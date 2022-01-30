#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
using namespace std;

size_t count_calls();

void arguments(int *a, int &b, int c);

void reset(int &i);
void reset(int *i);

void print_args(initializer_list<int> l);

void dosth(int &a, int &b);
void dosth(const int &a, const int &b);
void dosth(const int &a, int &b);

//functions that differ only in their return type cannot be overloaded
// int dosth(int &a, int &b);

#endif
