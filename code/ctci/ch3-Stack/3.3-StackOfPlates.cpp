#include <iostream>
#include <stack>

constexpr int MAX_STACKS = 8;
class StackOfPlates {
public:
    StackOfPlates() { stackArr = new std::stack<int>[MAX_STACKS]; };

    ~StackOfPlates() { delete[] stackArr; }
    void pop() {
        if (stackArr[currStack].empty()) {
            if (currStack == 0) {
                std::cout << "empty data" << std::endl;
                return;
            }
            currStack--;
        }
        stackArr[currStack].pop();
    };

    int top() {
        if (stackArr[currStack].empty()) {
            if (currStack == 0) { std::cout << "empty data" << std::endl; }
            currStack--;
        }
        return stackArr[currStack].top();
    };
    void push(int value) {
        if (stackArr[currStack].size() > threshold) { currStack++; }
        stackArr[currStack].push(value);
    };
    void popAt(int index) { stackArr[index].pop(); };

    bool empty() const { return (currStack == 0 && stackArr[currStack].empty()); }

private:
    std::stack<int> *stackArr;
    int threshold{4};
    int currStack{0};
};

int main(void) {
    StackOfPlates s;
    for (auto i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}) { s.push(i); }

    while (!s.empty()) {
        std::cout << s.top() << std::endl;
        s.pop();
    }

    return 0;
}
