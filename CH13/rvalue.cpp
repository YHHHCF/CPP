#include <iostream>

using std::cout; using std::endl; using std::string;

int main() {
    // 1. rvalue references
    int i1 = 42;
    int &ri1 = i1;
    // int &&rri1 = i1; rvalue ref cannot bind to lvalue

    // int &ri2 = i1 * 2; // lvalue ref cannot bind to rvalue
    const int &ri2c = i1 * 2;
    int &&rri2 = i1 * 2;
    // int &&rri3 = rri2; // rvalue ref rri2 is an lvalue
    
    // std::move yields the rvalue of lvalue rri2
    int &&rri3 = std::move(rri2);
    cout << &ri2c << ", " << &rri2 << ", " << &rri3 << endl;

    // 2. rvalue member functions could be called
    string s1 = "erbao";
    string s2 = "huang";
    cout << (s1 + s2).find('g') << endl; // at idx 9 of "erbaohuang"
    s1 + s2 = "ha";
    cout << s1 + s2 << endl; // the above rvalue is destroyed and this is a new one

    return 0;
}
