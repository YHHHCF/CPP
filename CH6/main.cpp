#include "function.h"

int main() {
    // cout << ctr << endl; // compile error, cannot use outside of count_calls()

    for (int i = 0; i < 10; ++i) {
        cout << count_calls() << endl;
    }

    // cout << ctr << endl; // compile error
}
