#include <iostream>
using namespace std;

int main() {
    // 1. modify string
    string s = "Hello, World!!!";
    cout << s.substr(7, 5) << endl; // from 'W' to 'd'
    cout << s.substr(7) << endl; // from 'W' to end

    s.insert(7, "my ");
    cout << s << endl;
    s.insert(7, 3, ' ');
    cout << s << endl;
    s.erase(7, 3);
    cout << s << endl;

    // 2. search
    string s1 = "abcabcabcabc";
    cout << s1.find("cabc") << endl; // first one
    cout << s1.rfind("bc") << endl; // last one

    // 3. compare
    string s2 = "erbao", s3 = "erbao", s4 = "erbao_huang";
    cout << s2.compare(s3) << endl;
    cout << (s2 == s3) << endl;
    cout << s2.compare(s4) << endl;
    cout << s4.compare(s2) << endl;

    // 4. numeric conversion
    int i = 128;
    string num = to_string(i);
    cout << num << ", " << stod(num) << ", " << stoi(num) << endl;
    double d2 = 11.1;
    cout << to_string(d2) << ", " << to_string(d2).substr(1) << endl;

    return 0;
}
