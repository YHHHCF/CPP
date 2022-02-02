#include <iostream>
#include <vector>
using namespace std;

void print_vec_addr_val(const vector<int> &v, string s) {
    cout << s << ": " << v.size() << endl;
    for (const auto &i : v) {
        cout << &i << ": " << i << endl;
    }
}

void print_str_vec(const vector<string> &v) {
    for (const auto &s : v) {
        cout << s << " ";
    }
    cout << endl;
}

bool isLarger(int i1, int i2) {
    return i1 > i2;
}

bool isShorter(string s1, string s2) {
    return s1.size() < s2.size();
}

int main() {
    // 1. sort
    vector<int> v1 = {1, 3, 2, 4, 5, 2, 3};

    print_vec_addr_val(v1, "v1");
    sort(v1.begin(), v1.end());
    print_vec_addr_val(v1, "v1");

    auto v1_end = unique(v1.begin(), v1.end());
    print_vec_addr_val(v1, "v1");
    v1.erase(v1_end, v1.end()); // erase from v1_end to v1.end()
    print_vec_addr_val(v1, "v1");

    // 2. sort with predicate
    sort(v1.begin(), v1.end(), isLarger);
    print_vec_addr_val(v1, "v1");

    vector<string> str_vec = {"fada", "faa", "ermte", "arfniaunfi", "gi"};
    print_str_vec(str_vec);
    sort(str_vec.begin(), str_vec.end());
    print_str_vec(str_vec);
    sort(str_vec.begin(), str_vec.end(), isShorter);
    print_str_vec(str_vec);

    return 0;
}
