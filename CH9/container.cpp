#include <iostream>
#include <vector>
using namespace std;

void print_vector_addr_value(const vector<int> &seq, string name) {
    cout << name << endl;
    for (auto &item : seq) {
        cout << &item << ": " << item << endl;
    }
}

int main() {
    // 1. iterator
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int>::iterator itb = v1.begin();
    vector<int>::iterator ite = v1.end();

    vector<int>::difference_type count = ite - itb;
    cout << count << endl;

    vector<int>::size_type size = v1.size();
    cout << size << endl;
    cout << v1.empty() << endl;

    for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it) {
        (*it) *= 2;
    }

    // use const version when do not need to write
    for (vector<int>::const_iterator it = v1.cbegin(); \
        it != v1.cend(); ++it) {
        // (*it) *= 2; compile error, const_iter could not modify elements
        cout << (*it) << endl;
    }

    // iterate in reverse order
    for (vector<int>::const_iterator it = v1.cend() - 1; \
         it >= v1.cbegin(); --it) {
        cout << (*it) << endl;
    }

    // 2. constructor
    vector<int> v2 = v1;
    vector<int> v3(v1);

    cout << "v1 == v2: " << (v1 == v2) << endl;

    // v2, v3 are copies for v1 with diff address
    print_vector_addr_value(v1, "v1");
    print_vector_addr_value(v2, "v2");
    print_vector_addr_value(v3, "v3");

    // size related constructors are only for seq containers
    vector<int> v4(5); // 5 zeros
    vector<int> v5(8, 3); // 8 threes

    print_vector_addr_value(v4, "v4");
    print_vector_addr_value(v5, "v5");

    v4 = v5; // now it has 8 elements (compiler knows the space needed)
    print_vector_addr_value(v4, "v4");

    // 3. swap is constant time
    vector<int> v6(3, 1);
    vector<int> v7(4, 2);

    print_vector_addr_value(v6, "v6");
    print_vector_addr_value(v7, "v7");

    swap(v6, v7); // swap v6 and v7 reference, no copy on underlying items
    print_vector_addr_value(v6, "v6");
    print_vector_addr_value(v7, "v7");

    v6.swap(v7); // same as swap(v6, v7);
    print_vector_addr_value(v6, "v6");
    print_vector_addr_value(v7, "v7");

    return 0;
}
