#include <iostream>
using namespace std;

int main() {
    // 1. allocate memory for slots
    allocator<int> alloc; // can allocate string

    // p points to 10 unconstructed strings;
    int n = 10;
    auto const p = alloc.allocate(n); // a pointer
    auto const p_end = p + n;
    cout << p << ": " << *p << endl; // unconstructed, undefined
    cout << p_end << endl;

    // 2. construct each slot
    auto q = p;
    for (int i = 0; i < n; ++i) {
        alloc.construct(q++, i * 10);
    }

    q = p;
    for (int i = 0; i < n; ++i) {
        cout << q << ":" << *q << " ";
        ++q;
    }
    cout << endl;

    // 3. destory or deconstruct each slot
    // the line below compiles but it is wrong to destroy
    // an object that is not constructed
    // alloc.destroy(q);
    
    while(q != p) {
        alloc.destroy(--q);
    }

    while(q != p_end) {
        cout << q << ":" << *q << " "; // undefined
        ++q;
    }
    cout << endl;
    q = p;

    // 4. deallocate memory
    // p and n must match one call to allocate()
    alloc.deallocate(p, n);
    cout << p << endl;
    while(q != p_end) {
        cout << q << ":" << *q << " "; // undefined
        ++q;
    }
    cout << endl;

    // 5. allocate for a ptr element
    allocator<int *> alloc_int_ptr;
    auto int_ptr_ptr = alloc_int_ptr.allocate(1);
    int val = 99;
    alloc_int_ptr.construct(int_ptr_ptr, &val);

    // int_ptr_ptr is a pointer to an allocated memory
    // that allocated memory stores the ptr of val
    cout << int_ptr_ptr << " -> " << *int_ptr_ptr \
         << " -> " << **int_ptr_ptr << endl;

    auto mark_int = *int_ptr_ptr;

    alloc_int_ptr.destroy(int_ptr_ptr);
    alloc_int_ptr.deallocate(int_ptr_ptr, 1);

    // the memory int_ptr_ptr points to is cleared
    // however val still exists and not destroyed
    // only allocated slots (to store pointers) are cleared
    // the values pointers point to are not destroyed
    cout << int_ptr_ptr << " -> " << *int_ptr_ptr << endl;
    cout << mark_int << " -> " << *mark_int << endl;

    // 6. allocate for a string element
    allocator<string> alloc_str;
    auto str_ptr = alloc_str.allocate(1);
    string str1 = "erbao";
    alloc_str.construct(str_ptr, str1);

    cout << str_ptr << " <- " << &str1 << endl;
    cout << str_ptr << " -> " << *str_ptr << endl;

    alloc_str.destroy(str_ptr);

    // string destructed, may still has the same value
    cout << str_ptr << " -> " << *str_ptr << endl;

    alloc_str.deallocate(str_ptr, 1);

    // the memory is deallocated, value is waped out
    cout << str_ptr << " -> " << *str_ptr << endl;

    return 0;
}
