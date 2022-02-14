#include <iostream>
#include "function_template.h"

using std::cout; using std::endl;

int main() {
    // 1. function template

    // compiler deduct int as template arguments
    // and bind int to template parameter T
    // compiler instantiates when it reaches the line below
    cout << compare(1, 0) << endl;

    // nontype template arguments must be constexpr
    cout << compare("erbao", "h") << endl;


    return 0;
}
