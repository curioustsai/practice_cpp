/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
*/

#include <gtest/gtest.h>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    void insertNode(ListNode*& head, int val) {
        if (head == nullptr) {
            head = new ListNode(val);
            return;
        }

        ListNode* ptr = head;
        while (ptr->next) { ptr = ptr->next; }
        ptr->next = new ListNode(val);

        return;
    }

    void removeList(ListNode*& head) {
        if (head == nullptr) return;
        ListNode* ptr = head;
        while (ptr->next) {
            ListNode* temp = ptr;
            ptr = ptr->next;
            delete temp;
        }
        head = nullptr;
        return;
    }

    //https://leetcode.com/problems/reverse-linked-list/discuss/58130/C%2B%2B-Iterative-and-Recursive
    // nullptr -> 5 -> 4 -> 3 -> 2 -> 1 -> nullptr
    // nullptr <- 5 <- 4 <- 3 <- 2 <- 1 <- nullptr
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void displayList(ListNode* head) {
        ListNode* ptr = head;
        while (ptr) {
            cout << ptr->val << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

TEST(ListNode, insert) {
    Solution sol;
    ListNode* head = nullptr;
    sol.insertNode(head, 5);
    sol.insertNode(head, 4);
    sol.insertNode(head, 3);
    sol.insertNode(head, 2);
    sol.insertNode(head, 1);

    sol.displayList(head);
    head = sol.reverseList(head);
    sol.displayList(head);

    sol.removeList(head);
}
