/*
 * Cicular loop
 */

#include <stdio.h>

#include "Node.h"

Node<char>* findCircularBegin(Node<char> *head) {
    // use fast and slow running technical
    Node<char> *fast, *slow;
    fast = head;
    slow = head;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;

        // meets at collision point
        if (fast == slow) {
            break;
        }
    }

    // no meeting point
    if (fast == nullptr || fast->next == nullptr) {
        return nullptr;
    }

    // move slow to head, and fast stay where it is
    // they will meets at beginning of the loop
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // both point to the beginning of the loop
    return fast;
}

int main(void) { 
    Node<char> *list = nullptr;
    list = new Node<char>('A');
    list->next = new Node<char>('B');
    Node<char> *c = new Node<char>('C');
    list->next->next = c;
    list->next->next->next = new Node<char>('D');
    list->next->next->next->next = new Node<char>('E');
    list->next->next->next->next->next = c;

    Node<char> *begin = findCircularBegin(list);
    if (begin)
        std::cout << begin->data << std::endl;

    return 0;
}
