#include <iostream>
using namespace std;

int main() {
    int a = 1, b = 3;
    double slope = static_cast<double>(a) / b;
    cout << slope << endl;

    void *slopep = &slope;
    // cout << *slopep << endl; // compile error
    cout << *(static_cast<double*>(slopep)) << endl;

    return 0;
}
