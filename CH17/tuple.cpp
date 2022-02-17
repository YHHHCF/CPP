#include <iostream>
#include <vector>
using std::tuple; using std::get;
using std::cout; using std::endl;
using std::string; using std::vector;

vector<tuple<string, int>> make_vec(const vector<string> &names) {
    vector<tuple<string, int>> v;
    for (size_t i = 0; i < names.size(); ++i) {
        v.push_back(make_tuple(names[i], static_cast<int>(i)));
    }

    return v;
}

void print_vec(const vector<tuple<string, int>> &v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << &(get<0>(v[i])) << ": " << get<0>(v[i]) << ", ";
        cout << &(get<1>(v[i])) << ": " << get<1>(v[i]) << endl;
    }
}

int main() {
    tuple<int, double, string> tp(11, 22., "erbao");
    ++get<0>(tp);
    cout << get<0>(tp) << ", "
         << get<1>(tp) << ", "
         << get<2>(tp) << endl;

    // get<3>(tp); // compile time error

    vector<string> names = {"A", "B", "C"};
    vector<tuple<string, int>> vec = make_vec(names);
    print_vec(vec);

    return 0;
}
