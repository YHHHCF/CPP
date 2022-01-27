#include <iostream>
using namespace std;

int main() {
    // 1. init array
    int arr1[3] = {111, 222};
    int arr2[] = {11, 22};

    for (int i = 0; i < 3; ++i) {
        cout << arr1[i] << ", " << arr2[i] << endl;
    }

    char s1[] = {'e', 'r', 'b', 'a', 'o'}; // size is 5
    char s2[] = {'e', 'r', 'b', 'a', 'o', '\0'}; // size is 6
    char s3[] = "erbao"; // size is 6

    cout << s1 << ": " << (sizeof(s1) / sizeof(s1[0])) << endl;
    cout << s2 << ": " << (sizeof(s2) / sizeof(s2[0])) << endl;
    cout << s3 << ": " << (sizeof(s3) / sizeof(s3[0])) << endl;

    // 2. array of pointers
    int *ptrs[10] = {}; // an array of 10 pointers to int, zero initialized

    for (auto ptr : ptrs) {
        cout << ptr << endl;
    }

    // int &refs[10]; // compile error

    // 2. array from pointer and iterator point of view
    int arr[10] = {1, 2, 3};
    int *b = begin(arr);
    int *e = end(arr);

    for (auto it = b; it != e; ++it) {
        cout << *it << endl;
    }

    for (auto it = arr; it != e; ++it) {
        cout << *it << endl;
    }

    // 3. n-d array
    int ndarr[3][4] = {};

    // modify each object in the array
    for (auto &row : ndarr) {
        for (auto &item : row) {
            item = 1;
        }
    }

    // row is the reference of row in ndarr, but item is just copy
    for (auto &row : ndarr) {
        for (auto item : row) {
            cout << item << endl;
        }
    }

    // // row is just int*
    // for (auto row : ndarr) {
    //     for (auto item : row) { // compile error
    //         cout << item << endl;
    //     }
    // }


    return 0;
}
