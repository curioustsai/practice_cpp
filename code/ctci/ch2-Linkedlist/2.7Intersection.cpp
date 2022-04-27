/*
 * Check if two linked lists are intersection
 *
 */

#include <iostream>

#include "Node.h"

int listLen(Node<char> *list) {
    Node<char> *ptr = list;
    int len = 0;
    while (ptr) {
        len++;
        ptr = ptr->next;
    }

    return len;
}

Node<char> *isIntersection(Node<char> *list1, Node<char> *list2) {
    int len1 = listLen(list1);
    int len2 = listLen(list2);

    Node<char> *ptrlong = (len1 > len2) ? list1 : list2;
    Node<char> *ptrshort = (len1 > len2) ? list2 : list1;
    int lenlong = (len1 > len2) ? len1 : len2;
    int lenshort = (len1 > len2) ? len2 : len1;
    int lendiff = lenlong - lenshort;
    int shift = 0;

    // shift the ptrlong, start with the same length
    while (ptrlong && shift < lendiff) {
        ptrlong = ptrlong->next;
        shift++;
    }

    // if intersection return the first intersection node
    // else return nullptr
    // once we find the intersection node, the rest of linked list is identical
    while (ptrlong && ptrshort) {
        if (ptrlong == ptrshort) return ptrlong;

        ptrlong = ptrlong->next;
        ptrshort = ptrshort->next;
    }

    return nullptr;
}

int main() {
    Node<char> *list1 = nullptr;
    Node<char> *list2 = nullptr;

    /*
     *      a -> b \
     *             f -> g -> h
     * c -> d -> e /
     */
    list1 = new Node<char>{'a'};
    list1->next = new Node<char>{'b'};

    list2 = new Node<char>{'c'};
    list2->next = new Node<char>{'d'};
    list2->next->next = new Node<char>{'e'};

    Node<char> *connect = new Node<char>{'f'};
    connect->next = new Node<char>{'g'};
    connect->next->next = new Node<char>{'h'};

    list1->next->next = connect;
    list2->next->next->next = connect;

    Node<char> *inter = isIntersection(list1, list2);
    if (inter) { std::cout << inter->data << std::endl; }

    removeNodes(&list1);

    return 0;
}
