/**
 *  Cracking the coding interview edition 6
 *  Problem 2.4 Partition:
 *  Write code to partition linked list around a value x, such that
 *  nodes less than x come before all the nodes greater than or equal to x.
 *  If x is in the list, the values of x only need to be after the elements
 *  less than x. Example 3-->5-->8-->5-->10-->2-->1 (x = 5)
 *  3-->1-->2-->10-->5-->5-->8
 *
 *  Approach:
 *  Start with first node, and add every thing bigger or equal to x at tail
 *  and smaller values at head.
 */

#include "Node.h"
#include <stdio.h>

Node<int> *partition(Node<int> *head, int value) {
    Node<int> *largeList = nullptr;
    Node<int> *smallList = nullptr;

    Node<int> *ptr = head;
    while (ptr) {
        if (ptr->data > value) {
            appendNode(largeList, ptr->data);
        } else {
            appendNode(smallList, ptr->data);
        }
        ptr = ptr->next;
    }

    ptr = largeList;
    while (ptr->next) { ptr = ptr->next; }
    ptr->next = smallList;

    return largeList;
}

int main() {
    Node<int> *head = new Node<int>(3);
    appendNode(head, 5);
    appendNode(head, 8);
    appendNode(head, 5);
    appendNode(head, 10);
    appendNode(head, 2);
    appendNode(head, 1);

    printNodes(head);

    Node<int> *part = partition(head, 5);

    printNodes(part);
    removeNodes(&head);
    removeNodes(&part);

    return 0;
}
