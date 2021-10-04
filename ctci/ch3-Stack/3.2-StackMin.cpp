#include <iostream>

// constexpr int stacks = 3;
//
// template <class T>
// class ThreeInOneStack {
// public:
//     ThreeInOneStack(int size) : _stackSize(size) {
//         _arraySize = stacks * _stackSize;
//         _data = new T[_arraySize];
//     }
//     ~ThreeInOneStack() { delete[] _data; }
//
// private:
//     int _stackSize;
//     int _arraySize;
//     T* _data;
// };

template <class T>
class Stack {
public:
    Stack() = delete;
    Stack(int size) : _size(size) { _data = new T[_size]; };
    ~Stack() { delete[] _data; }

    // T* min();
    T& top() const { return _data[_count - 1]; }
    void push(T data) {
        if (_count > _size) return;
        _data[_count++] = data;
    }
    void empty() {
        memset(_data, 0, sizeof(T) * _size);
        _size = 0;
    };
    int size() const { return _size; }
    void pop() {
        _data[_count - 1] = 0;
        _count--;
    }

private:
    T* _data{nullptr};
    int _size{32};
    int _count{0};
};

int main() {
    Stack<int> s{32};
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;

    return 0;
}
