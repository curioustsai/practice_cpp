/*
 * Implement a queue via 2 stacks
 */
#include <iostream>
#include <stack>

using namespace std;
class MyQueue {
public:
    void Enque(int value) {
        if (s1.empty()) {
            s2.push(value);
        }

        if (s2.empty()) {
            s1.push(value);
        }
    };

    int Deque() {
        stack<int> *emptyStack = (s1.empty()) ? &s1 : &s2;
        stack<int> *dataStack = (s1.empty()) ? &s2 : &s1;

        int top;
        while (!dataStack->empty()) {
            top = dataStack->top();
            dataStack->pop();
            emptyStack->push(top);
        }
        emptyStack->pop();

        while (!emptyStack->empty()) {
            dataStack->push(emptyStack->top());
            emptyStack->pop();
        }
        return top;
    };

    bool Empty() const { return (s1.empty() && s2.empty()); };

private:
    stack<int> s1, s2;
};

int main() {
    MyQueue q;

    for (int i : {1, 2, 3, 4, 5, 6, 7, 8}) {
        q.Enque(i);
    }

    while (!q.Empty()) {
        cout << q.Deque() << endl;
    };

    return 0;
}
