#include <iostream>
using namespace std;



int main() {
    string name = "erbao_huang";

    // begin(), end() returns non-const iterator (pointer)
    for (auto it = name.begin(); it != name.end(); ++it) {
        (*it) = toupper(*it);
    }

    cout << name << endl;

    // cbegin(), cend() returns const iterator
    for (auto it = name.cbegin(); it < name.cend(); it += 3) {
        // (*it) = tolower(*it); // compile error
        cout << (*it) << endl;
    }
    return 0;
}
