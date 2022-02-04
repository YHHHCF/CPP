#include <iostream>
#include "StrBlob.h"

using namespace std;

int main() {
    // 1. basics
    shared_ptr<string> p1;
    cout << p1 << endl; // default is nullptr

    p1 = make_shared<string>("erbao");
    cout << p1 << ": " << *p1 << endl;

    auto p2_1 = make_shared<int>(3);
    cout << p2_1 << ": " << *p2_1 << endl;

    auto p2_2(p2_1); // ref count +1
    cout << p2_2 << ": " << *p2_2 << endl;

    auto p2_3 = make_shared<int>(4);
    cout << p2_3 << ": " << *p2_3 << endl;

    // int 3 ref_cnt++
    // int 4 ref_cnt--, be zero, freed
    cout << p2_3.use_count() << ", " << p2_3.unique() << endl;
    p2_3 = p2_2;
    cout << p2_3.use_count() << ", " << p2_3.unique() << endl;

    // 2. example
    StrBlob b1;
    {
        StrBlob b2 = {"abc", "bcd", "cde"};
        b2.print_addr();
        b1 = b2; // shared_ptr is copied to b1, vector elements are the same
        b1.print_addr();
        b2.push_back("def");
        b1.print_size();
        b2.print_size();
        b1.print_ref_cnt(); // 2
    }
    b1.print_addr();
    b1.print_size();
    b1.print_ref_cnt(); // 1
    // b2.print_size(); // no longer exists

    return 0;
}
