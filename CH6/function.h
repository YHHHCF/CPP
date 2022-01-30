#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
using namespace std;

size_t count_calls();

void arguments(int *a, int &b, int c);

void reset(int &i);
void reset(int *i);

void print_args(initializer_list<int> l);

#endif
