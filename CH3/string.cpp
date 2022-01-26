#include <iostream>
using namespace std;

int main() {
    string a = "";
    string b;
    cout << a.empty() << endl;
    cout << b.empty() << endl;
    cout << (a==b) << endl;
    cout << a.size() << endl;

    string c = "erbao";
    unsigned c_size = c.size(); // or auto
    cout << c_size << endl;

    string d = "erbao", e = " huang";
    string name = d + e;
    cout << name << endl;
    cout << d + " huang" << endl;

    for (auto c : name) {
        cout << c << " ";
    }
    cout << endl;

    // change each char in string to uppercase
    for (auto &c : name) { // c needs to be a ref instead of copy
        c = toupper(c);
    }
    cout << name << endl;

    // iterate
    for (unsigned i = 0; i < name.size(); ++i) {
        auto &c = name[i];
        c = tolower(c);
    }
    cout << name << endl;
    
    return 0;
}
