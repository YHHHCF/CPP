#include <iostream>

int main() {
    int i = 1;
    float j = 2.0;

    // int &ri; // illegal
    // int &ri = j; // illegal
    int &ri = i;

    std::cout << i << ", " << ri << std::endl;

    ri = 3;
    std::cout << i << ", " << ri << std::endl;

    int &ri2 = ri;
    ri2 = 4;

    std::cout << i << ", " << ri << ", " << ri2 << std::endl;

    int i3 = ri2; // i3 is a new object
    i3 = 5;
    std::cout << i << ", " << ri << ", " << ri2 << ", " << i3 << std::endl;

    ri = i3; // copy value to i/ri/ri2, but ri won't refer to i3
    std::cout << i << ", " << ri << ", " << ri2 << ", " << i3 << std::endl;

    i3 = 6;
    std::cout << i << ", " << ri << ", " << ri2 << ", " << i3 << std::endl;

    return 0;
}
