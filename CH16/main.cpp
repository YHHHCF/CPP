#include <iostream>
#include "function_template.h"
#include "class_template.h"

using std::cout; using std::endl;

template <typename T, typename... Args>
void print_args(const T &t) {
    cout << "The last one: " << t << endl;
}

template <typename T, typename... Args>
void print_args(const T &t, const Args&... rest) {
    cout << "This one: " << t << endl;
    cout << "Remaining " << sizeof...(Args) << endl;
    // cout << "Remaining " << sizeof...(rest) << endl; // also works
    print_args(rest...); // call recursively using rest args
}

int main() {
    // 1. function template

    // compiler deduce int as template arguments
    // and bind int to template parameter T
    // compiler instantiates when it reaches the line below
    cout << compare(1, 0) << endl;

    // nontype template arguments must be constexpr ("erbao", "h")
    cout << compare("erbao", "h") << endl;

    // 2. class template
    // need to provide template args explicitly, no compiler deduce
    Blob<int> ia1;
    Blob<int> ia2 = {1, 2, 3};
    Blob<string> name = {"erbao", "huang"};

    // 3. variadic templates
    print_args(1, 2, "erbao", "huang", 10.0);
    print_args(11);

    return 0;
}
