#include <iostream>
#include "Sales_data.h"
#include "Screen.h"

using namespace std;

int main() {
    Sales_data s1;
    const Sales_data s2;

    s1.isbn();
    s2.isbn();

    Screen screen1(3, 5, 'c');
    const Screen screen2(4, 6, 'b');

    screen1.display(cout); // overload non-const version
    screen2.display(cout); // overload const version

    return 0;
}
