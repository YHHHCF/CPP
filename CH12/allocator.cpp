#include <iostream>
using namespace std;

int main() {
    // 1. allocate memory for slots
    allocator<int> alloc; // can allocate string

    // p points to 10 unconstructed strings;
    int n = 10;
    auto const p = alloc.allocate(n);
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
    while(q != p_end) {
        cout << q << ":" << *q << " "; // undefined
        ++q;
    }
    cout << endl;

    return 0;
}
