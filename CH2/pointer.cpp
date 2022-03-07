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

    int *&rpi = pi; // rpi is an alias of pi, pointer could be referenced
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
    // *vp = 4; // cannot assign through void ptr, cannot dereference void ptr
    *(static_cast<int*>(vp)) = 9;
    std::cout << *(static_cast<int*>(vp)) << ", " << *pi << std::endl; // cannot 

    float j = 3.1;
    vp = &j; // could be assigned pointer of any type
    std::cout << vp << ", " << *(static_cast<float*>(vp)) << std::endl;

    return 0;
}
