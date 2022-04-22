#include "Node.h"

Node<int>* sum(Node<int>* node1, Node<int>* node2) {
    if (node1 == nullptr) return node2;
    if (node2 == nullptr) return node1;

    int carrier = 0;
    Node<int>* result = nullptr;
    Node<int>* ptr1 = node1;
    Node<int>* ptr2 = node2;

    while (ptr1 && ptr2) {
        int sum = ptr1->data + ptr2->data + carrier;
        if (sum >= 10) {
            carrier = 1;
            sum -= 10;
        } else {
            carrier = 0;
        }
        appendNode(result, sum);
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    while (ptr1) {
        int sum = ptr1->data + carrier;
        if (sum >= 10) {
            carrier = 1;
            sum -= 10;
        } else {
            carrier = 0;
        }
        appendNode(result, sum);
        ptr1 = ptr1->next;
    }

    while (ptr2) {
        int sum = ptr2->data + carrier;
        if (sum >= 10) {
            carrier = 1;
            sum -= 10;
        } else {
            carrier = 0;
        }
        appendNode(result, sum);
        ptr2 = ptr2->next;
    }

    if (carrier)
        appendNode(result, carrier);

    return result;
}

int main() {
    Node<int>* num1 = nullptr;
    Node<int>* num2 = nullptr;
    appendNode(num1, 9);
    appendNode(num1, 9);
    appendNode(num1, 9);
    appendNode(num1, 9);
    appendNode(num1, 9);

    appendNode(num2, 9);
    appendNode(num2, 9);
    appendNode(num2, 9);

    printNodes(num1);
    printNodes(num2);
    
    Node<int>* result = sum(num1, num2);
    printNodes(result);

    removeNodes(&num1);
    removeNodes(&num2);

    return 0;
}
