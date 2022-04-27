#include <climits>
#include <iostream>
#include <stack>

class StackMin {
public:
    void pop();
    void push(int value);
    int top() const;
    int min() const;
    bool empty() const;

private:
    std::stack<int> stack;
    std::stack<int> stack_min;
};

void StackMin::push(int value) {
    stack.push(value);
    if (min() > value) stack_min.push(value);
}

int StackMin::min() const {
    if (stack_min.empty()) return INT_MAX;

    return stack_min.top();
}

void StackMin::pop() {
    if (stack.top() == min()) stack_min.pop();
    stack.pop();
}

int StackMin::top() const { return stack.top(); }

bool StackMin::empty() const { return stack.empty(); }

int main() {
    StackMin s;

    s.push(100);
    s.push(20);
    s.push(200);
    s.push(400);
    s.push(10);

    std::cout << s.min() << std::endl;
    s.pop();

    std::cout << s.min() << std::endl;
    s.pop();

    return 0;
}
