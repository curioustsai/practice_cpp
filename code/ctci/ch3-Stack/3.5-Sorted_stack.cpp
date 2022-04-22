/*
 * Sorted stack
 */
#include <iostream>
#include <stack>

using namespace std;
class SortedStack {
public:
    void pop() { s.pop(); };

    /* keep sorted when each push */
    void push(int value) {
        if (s.empty()) {
            s.push(value);
            return;
        }

        while (s.top() > value) {
            helper.push(s.top());
            s.pop();
        }
        s.push(value);

        while (!helper.empty()) {
            s.push(helper.top());
            helper.pop();
        }
    };

    int top() const { return s.top(); };
    bool empty() { return s.empty(); };

private:
    stack<int> s;
    stack<int> helper;
};

int main(void) {
    SortedStack s;
    for (int i : {1, 2, 4, 3, 7, 8, 10, 7, 3, 2,1}) {
        s.push(i);
    }

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}
