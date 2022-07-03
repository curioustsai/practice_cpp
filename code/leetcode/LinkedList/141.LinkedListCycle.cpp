/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.
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
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return false;

        ListNode *slow = head, *fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            if (slow == fast) return true;
            slow = slow->next;
            fast = fast->next->next;
        }

        return false;
    }

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

TEST(ListNode, Cycle1) {
    Solution sol;
    ListNode* head = nullptr;
    sol.insertNode(head, 3);
    sol.insertNode(head, 2);
    sol.insertNode(head, 0);
    // 3 -> 2 -> 0 ->loopback 3
    head->next->next->next = head;
    ASSERT_EQ(sol.hasCycle(head), true);
}

TEST(ListNode, Cycle2) {
    Solution sol;
    ListNode* head = nullptr;
    sol.insertNode(head, 1);
    sol.insertNode(head, 2);
    head->next->next = head;
    ASSERT_EQ(sol.hasCycle(head), true);
}

TEST(ListNode, Cycle3) {
    Solution sol;
    ListNode* head = nullptr;
    sol.insertNode(head, 1);

    ASSERT_EQ(sol.hasCycle(head), false);
}
