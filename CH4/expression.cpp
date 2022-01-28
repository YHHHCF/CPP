#include <iostream>
using namespace std;

int main() {
    // 1. assignment expression (a = 3) requires lvalue a as lhs
    // and it yields lvalue a, then we can dereference to get the address
    int a;
    cout << &(a = 3) << endl;

    // 2. diff between prefix and postfix ++
    // ++i expression yields lvalue after change
    // j++ expression yields rvalue as a copy before change
    int i = 3, j = 3;
    cout << (++i) << ", " << (j++) << endl;
    cout << &(++i) << endl;
    // cout << &(j++) << endl; // compile error

    // 3. dereference and ++
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *ptr = arr;

    while(ptr < end(arr)) {
        // dereference a copy of old value, then increase ptr
        // equivalent to *(ptr++)
        cout << *ptr++ << endl;
    }

    // 4. member access
    string str = "erbao";
    string *pstr = &str;

    cout << str.size() << ", " << pstr->size() << endl;

    // 5. sizeof
    int n[3] = {1, 3, 5};
    cout << sizeof(int) << ", " << sizeof(n) << endl;
    cout << sizeof(int*) << endl;

    // 6. comma
    int x = 33, y = 44, z = 55;
    cout << &x << ", " << &y << ", " << &z << endl;
    cout << &(x++, --y, ++z) << endl; // evaluates left to right, yields right


    return 0;
}
