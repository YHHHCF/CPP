#include <iostream>
#include <vector>
#include <list>

using namespace std;

void print_vector(const vector<int> &vec, string name) {
    cout << name << ": ";
    for (auto &item : vec) {
        cout << item << " ";
    }
    cout << endl;
}

void print_list(const list<int> &l, string name) {
    cout << name << ": ";
    for (auto &item : l) {
        cout << item << " ";
    }
    cout << endl;
}

int main() {
    // 1. add to front or end
    vector<int> v1 = {1, 2};
    print_vector(v1, "v1");
    v1.push_back(3);
    print_vector(v1, "v1");

    string s = "erba"; // string is also seq container
    cout << s << endl;
    s.push_back('o');
    cout << s << endl;

    list<int> l1 = {1, 2};
    print_list(l1, "l1");
    l1.push_back(3);
    l1.push_front(0);
    print_list(l1, "l1");

    // 2. insert
    vector<int>::iterator it1 = v1.begin() + 1;
    // insert to that iterator and the previous element moves back
    // returned value points to inserted value
    it1 = v1.insert(it1, -1);
    print_vector(v1, "v1");
    cout << (*it1) << endl;

    list<int>::iterator it2 = l1.begin();
    it2 = l1.insert(it2, -3);
    print_list(l1, "l1");
    cout << (*it2) << endl;

    // 3. access
    cout << "v1" << endl;
    cout << *(v1.begin()) << ", " << *(--v1.end()) << endl;
    cout << v1.front() << ", " << v1.back() << endl;
    cout << v1[0] << ", " << v1[v1.size() - 1] << endl;
    cout << v1.at(0) << ", " << v1.at(v1.size() - 1) << endl;

    cout << "l1" << endl;
    cout << *(l1.begin()) << ", " << *(--l1.end()) << endl;
    cout << l1.front() << ", " << l1.back() << endl;

    // ref
    auto v1b = v1.front(); // copy of first element
    auto &v1br = v1.front(); // ref of first element

    v1b = 11;
    print_vector(v1, "v1");
    v1br = 11;
    print_vector(v1, "v1");

    // 4. remove
    v1.pop_back();
    print_vector(v1, "v1");

    l1.pop_front();
    print_list(l1, "l1");
    l1.pop_back();
    print_list(l1, "l1");

    v1.erase(v1.begin() + 1);
    print_vector(v1, "v1");

    v1.resize(5, 6); // v1 resize to 5 element by appending 6s
    print_vector(v1, "v1");

    l1.resize(6); // append 0s
    print_list(l1, "l1");

    // 5. vector allocation
    vector<int> v2;
    cout << v2.capacity() << endl;

    for (int i = 0; i < 34; ++i) {
        v2.push_back(1);
        cout << v2.size() << ", " << v2.capacity() << endl;
    }

    v2.shrink_to_fit();
    cout << v2.size() << ", " << v2.capacity() << endl;

    v2.push_back(1);
    cout << v2.size() << ", " << v2.capacity() << endl;

    v2.reserve(100);
    cout << v2.size() << ", " << v2.capacity() << endl;

    string str = "erbao";
    cout << &str << ": " << str.size() << ", " << str.capacity() <<endl;
    str += '_';
    cout << &str << ": " << str.size() << ", " << str.capacity() <<endl;
    str.shrink_to_fit(); // not guranteed to change capacity
    cout << &str << ": " << str.size() << ", " << str.capacity() <<endl;
    str += "huang";
    cout << &str << ": " << str.size() << ", " << str.capacity() <<endl;

    return 0;
}
