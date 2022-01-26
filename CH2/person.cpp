#include<iostream>
#include "person.h"

int main() {
    Person p;
    std::cin >> p.name >> p.age;
    std::cout << p.name << ": " << p.age << std::endl;

    return 0;
}
