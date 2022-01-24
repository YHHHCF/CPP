#include <iostream>

int main() {
    int i = 1;
    int *pi = &i;

    std::cout << pi << std::endl; // pointer is address
    std::cout << &pi << std::endl; // pointer is an object that has address
    std::cout << *pi << std::endl;

    int &ri = i;
    int *pri = &ri;
    std::cout << pri << std::endl; // ri has no address, points to i's address

    *pi = 2;
    std::cout << i << std::endl;

    int *&rpi = pi; // rpi is an alia of pi, pointer could be referenced
    std::cout << rpi << ", " << *rpi << std::endl;

    int *p2;
    std::cout << p2 << ", " << *p2 << std::endl; // undefined behavior

    int *p3 = nullptr;
    std::cout << p3 << std::endl; // could not be dereferenced

    int **ppi = &pi;
    std::cout << ppi << ", " << *ppi << ", " << **ppi << std::endl;

    void *vp;
    vp = &i;
    std::cout << vp << std::endl;

    float j = 3.0;
    vp = &j; // could be assigned pointer of any type
    std::cout << vp << std::endl;

    return 0;
}
