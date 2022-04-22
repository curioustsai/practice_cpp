#include <iostream>

template <class T>
struct Node {
    Node *next;
    T data;

    Node() : next{nullptr}, data{0} {};
    Node(T d) : next{nullptr}, data{d} {};
};

// template <class T>
// void appendNode(Node<T> *&head, T data);
// template <class T>
// void printNodes(Node<T> *head);
// template <class T>
// void removeNodes(Node<T> **head);

template <class T>
void appendNode(Node<T> *&head, T data) {
    if (head == nullptr) {
        head = new Node<T>(data);
    } else {
        Node<T> *ptr = head;
        while (ptr->next) {
            ptr = ptr->next;
        }

        ptr->next = new Node<T>(data);
        return;
    }
}

template <class T>
void printNodes(Node<T> *head) {
    if (head == nullptr) return;

    Node<T> *ptr = head;
    std::cout << ptr->data << "->";
    while (ptr->next) {
        std::cout << ptr->next->data << "->";
        ptr = ptr->next;
    }

    std::cout << "nullptr" << std::endl;
}

template <class T>
void removeNodes(Node<T> **head) {
    if (head == nullptr) return;

    Node<T> *ptr = *head;
    while (ptr) {
        Node<T> *t = ptr;
        ptr = ptr->next;
        delete t;
    }
    *head = nullptr;
}
