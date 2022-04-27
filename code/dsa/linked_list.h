#pragma once

namespace dsa {
template <class T>
class ListNode {
public:
    void appendTail(T data);

private:
    ListNode<T> *_next{nullptr};
    T _data;
};

template <class T>
class Linkedlist {
public:
    Linkedlist();
};
} // namespace dsa
