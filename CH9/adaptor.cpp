#include <iostream>
#include <deque>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void pop_and_print_stack(stack<int> &s) {
    while(!s.empty()) {
        cout << s.top() << " "; // return back element but not remove
        s.pop(); // pop back element but not return
    }
    cout << endl;
}

int main() {
    // 1. stack
    deque<int> deq = {1, 2, 3, 4, 5};
    stack<int> s1(deq);

    stack<int> s2;
    for (int i = 0; i < 5; ++i) {
        s2.push(i+1);
    }

    pop_and_print_stack(s1);
    pop_and_print_stack(s2);

    cout << s1.size() << ", " << s2.size() << endl;

    // 2. queue
    queue<int> q;
    for (int i = 0; i < 5; ++i) {
        q.push(i+1);
    }

    cout << q.front() << ", " << q.back() << endl;
    q.pop(); // pop front
    cout << q.front() << ", " << q.back() << endl;

    return 0;
}
