#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<int> vec) {
    for (auto i : vec) {
        cout << i << " ";
    }
    cout << endl;
    return;
}

// we want to pass the reference to the arg instead of a copy
void print_vec_addr(vector<int> &vec) {
    cout << "========print_vec_addr_start========" << endl;
    for (int i  = 0; i < vec.size(); ++i) {
        cout << &vec[i] << endl;
    }
    cout << "=========print_vec_addr_end=========" << endl;
}

int main() {
    vector<int> v1 = {1, 2, 3};
    vector<int> v2{1, 2, 3};
    vector<int> v3(v1); // copy each value
    vector<int> v4 = v3; // copy each value
    vector<int> v5(10, 4); // 10 fours
    vector<int> v6(5); // 10 zeros
    vector<int> v7;
    for (int i = 0; i < 5; ++i) {
        v7.push_back(i);
    }

    for (auto &i : v1) {
        i *= i;
    }

    print_vec(v1);
    print_vec(v2);
    print_vec_addr(v1);
    print_vec_addr(v2);
    print_vec_addr(v3);
    print_vec_addr(v4);
    print_vec_addr(v5);
    print_vec_addr(v6);
    print_vec_addr(v7);

    cout << (v1 == v2) << ", " << (v2 == v3) << endl;

    return 0;
}
