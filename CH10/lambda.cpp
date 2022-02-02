#include <iostream>
#include <vector>
using namespace std;

void print_vec(const vector<int> &vec) {
    for (const auto &i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    // 1. lambda is a piece of callable code
    // can ignore param and return
    auto f1 = [] { return 3; };
    auto f2 = []() -> int { return 4; };
    cout << f1() << endl;
    cout << f2() << endl;

    // 2. argument passing
    auto f3 = [](int i1, int i2) { return i1 > i2; };
    cout << f3(1, 2) << ", " << f3(2, 1) << endl;

    // as a predicate
    vector<int> v1 = {1, 3, 4, 5, 2};
    print_vec(v1);
    sort(v1.begin(), v1.end());
    print_vec(v1);
    // binary predicate
    sort(v1.begin(), v1.end(), f3);
    print_vec(v1);

    // unary predicate
    for_each(v1.begin(), v1.end(), [](int i) { ++i; });
    print_vec(v1);
    for_each(v1.begin(), v1.end(), [](int &i) { ++i; });
    print_vec(v1);

    // 3. capture list (for local non-static vars)
    int a = 1, b = 2;
    cout << &a << ": " << a << endl;
    cout << &b << ": " << b << endl;

    // capture a and b by copying
    auto f4 = [a, b](){
        cout << &a << ": " << a << endl;
        cout << &b << ": " << b << endl;
    };

    f4();

    // capture a and b by referencing
    auto f5 = [&a, &b](){
        cout << &a << ": " << a << endl;
        cout << &b << ": " << b << endl;
    };

    f5();

    return 0;
}
