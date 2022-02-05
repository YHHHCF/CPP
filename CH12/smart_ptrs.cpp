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

    // 3. new and delete
    int *pi = new int(); // default init
    cout << pi << ": " << *pi << endl;

    string *ps = new string("erbao"); // init with value
    cout << ps << ": " << *ps << endl;

    auto ps2 = new auto(*ps); // auto type inference
    cout << ps2 << ": " << *ps2 << endl;

    const int *pci = new const int(2);
    cout << pci << ": " << *pci << endl;

    delete pi; // deallocate the memory, pi still holds the same addr
    // delete pi; // runtime error: pointer being freed was not allocated
    cout << pi << ": " << *pi << endl; // pi's memory stores undefined value
    pi = nullptr; // in case there are other users of pi

    delete ps;
    delete ps2;
    delete pci;
    ps = nullptr;
    ps2 = nullptr;
    pci = nullptr;

    // 4. convertion vs built-in ptr and shared_ptr
    int *on_heap = new int(100);
    cout << on_heap << endl;
    shared_ptr<int> p3(on_heap); // ref cnt is 1
    cout << p3 << ": " << *p3 << ", " << p3.use_count() << endl;

    // cause runtime err when shared_ptr free the memory
    // delete on_heap;

    int local = 101;
    int *p_local = &local;
    // cause runtime err below, local will be deallocated when
    // going out of scope, and then shared_ptr free it and get err
    // shared_ptr<int> p4(p_local);

    // 5. unique_ptr
    cout << "debug 5" << endl;
    unique_ptr<int> p4_1; // default is nullptr
    unique_ptr<int> p4_2(new int(42));
    // p4_1 = p4_2; // cannot assign another ptr to unique ptr

    cout << p4_2 << ": " << *p4_2 << endl;
    p4_1.reset(p4_2.release()); // control transfer from reset, release returns the prev ptr
    cout << p4_2 << endl; // after release it is nullptr
    cout << p4_1 << ": " << *p4_1 << endl; // control transferred
    
    unique_ptr<int> p4_3(p4_1.release()); // control transfer from constructor
    cout << p4_3 << ": " << *p4_3 << endl;

    p4_3.release();

    // 6. weak_ptr to prevent memory leak
    auto p5_1 = make_shared<int>(51);
    weak_ptr<int> p5_2(p5_1);
    cout << p5_1 << ", " << p5_2.lock() << endl;

    // this returns p5_1's ref cnt, weak_ptr does not increase ref cnt
    cout << p5_2.use_count() << endl;

    weak_ptr<int> p5_3(p5_2);
    cout << p5_3.use_count() << endl; // p5_1's ref cnt

    p5_1.reset(); // release memory even though 2 weak ptrs points it, no memory leak will happen
    cout << p5_1 << ", " << p5_2.lock() << ", " << p5_3.lock() << endl; // null after release
    cout << p5_2.use_count() << endl; // null has 0 ref cnt
    // cout << p5_1 << ", " << p5_2 << endl;

    return 0;
}
