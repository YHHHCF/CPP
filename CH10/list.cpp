#include <iostream>
#include <list>

using namespace std;

void print_list(const list<int> &l) {
    for (const auto i : l) {
        cout << i << " ";
    }
    cout << endl;
}

bool isLarger(int i1, int i2) {
    return i1 > i2;
}

bool isNegative(int i) {
    return i < 0;
}

int main() {
    list<int> l1 = {2, 3, 1, 4, 7, 6, 5};
    list<int> l2 = {-1, -3, -2, 0, 8, 9};

    l1.sort(isLarger);
    l2.sort(isLarger);
    print_list(l1);
    print_list(l2);

    l1.merge(l2, isLarger);
    print_list(l1);

    l1.sort();
    print_list(l1);

    l1.reverse();
    print_list(l1);

    l1.remove_if(isNegative);
    print_list(l1);

    l1.remove(5);
    print_list(l1);

    list<int> l3 = {1, 1, 2, 2, 3};
    l3.unique();
    print_list(l3);

    return 0;
}
