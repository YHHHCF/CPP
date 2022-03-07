#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int b = 4;

    try {
        if (a > b) {
            throw runtime_error("a > b");
        }
        if (a < b) {
            throw runtime_error("a < b"); // exit this code block
        }
        // will not be executed if throw exception above
        cout << a << ", " << b << endl;
    } catch (runtime_error1 err) {
        // exception handler
        cout << "Exception: " << err.what() << endl;
        a = b;
    }

    cout << a << ", " << b << endl;

    return 0;
}
