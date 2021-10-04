/*
 * Check if a linked-list palindrome
 * palindrome: symmetric word
 * TODO: improve algorithm
 */

#include <stdio.h>

#include "Node.h"

Node<char> *reverse_list(Node<char> *head) {
    Node<char> *reverse = nullptr;
    Node<char> *curr = head;

    while (curr) {
        Node<char> *t = (curr->next) ? curr->next : nullptr;
        curr->next = reverse;
        reverse = curr;
        curr = t;
    }

    return reverse;
}

/*
 * Method 1: work but not pretty
 * Reverse all linked list and compare with the oringal one
 */
bool isPalindrome(Node<char> *head) {
    // copy linked list;
    Node<char> *newCopy = nullptr;
    Node<char> *ptr = head;

    while (ptr) {
        appendNode(newCopy, ptr->data);
        ptr = ptr->next;
    }
    // reverse linked list
    Node<char> *reverse = reverse_list(head);

    // check list equals
    printNodes(newCopy);
    printNodes(reverse);

    Node<char> *ptr1 = newCopy, *ptr2 = reverse;

    while (ptr1 && ptr2) {
        if (ptr1->data != ptr2->data) return false;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return true;
}

/*
 * Method 2:
 * 1) Find the middle node
 * 2) Reverse and the second half
 * 3) Compare the second half with first half
 */
bool isPalindrome2(Node<char> *head) {
    // find the middle node
    Node<char> *fastptr = head;
    Node<char> *slowptr = head;

    /*
     * take care of odd or even linked list
     * K step
     * Even list
     * Node0-> Node1-> ... ->NodeK->...-> Node2K -> nullptr
     * Stop at Node 2K
     *
     * Odd list
     * Node0-> Node1-> ... ->NodeK->...-> Node2K -> NodeK2+1 -> nullptr
     * Break
     * fastptr at nullptr
     */

    while (fastptr && fastptr->next) {
        if (fastptr->next->next == nullptr) {
            fastptr = fastptr->next;
            break;
        }
        fastptr = fastptr->next->next;
        slowptr = slowptr->next;
    }

    std::cout << "fastptr: " << fastptr->data << std::endl;
    std::cout << "slowptr: " << slowptr->data << std::endl;

    Node<char> *second_half = slowptr->next;
    Node<char> *reverse = reverse_list(second_half);
    Node<char> *ptr1 = head;
    Node<char> *ptr2 = reverse;

    printNodes(reverse);

    while (ptr2 != nullptr) {
        if (ptr2->data != ptr1->data)
            return false;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    // Bad clean
    removeNodes(&head);
    removeNodes(&reverse);

    return true;
}

int main() {
    Node<char> *head = nullptr;
    appendNode<char>(head, 'a');
    appendNode<char>(head, 'b');
    appendNode<char>(head, 'c');
    appendNode<char>(head, 'b');
    appendNode<char>(head, 'f');

    printNodes<char>(head);

    std::cout << std::boolalpha << isPalindrome2(head) << std::endl;

    Node<char> *head2 = nullptr;
    appendNode<char>(head2, 'a');
    appendNode<char>(head2, 'b');
    appendNode<char>(head2, 'c');
    appendNode<char>(head2, 'c');
    appendNode<char>(head2, 'b');
    appendNode<char>(head2, 'f');

    printNodes<char>(head2);
    std::cout << std::boolalpha << isPalindrome2(head2) << std::endl;

    return 0;
}
