/*
You are given the head of a singly linked-list. The list can be represented as:
L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.


https://leetcode.com/problems/reorder-list/
*/

#include <gtest/gtest.h>

#include <iostream>
#include <stack>

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
    // Time complexity O(n), space complexity O(n)
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;

        stack<ListNode*> st;
        ListNode* ptr = head;
        int size = 0;

        while (ptr) {
            st.push(ptr);
            ptr = ptr->next;
            size++;
        }

        ptr = head;
        for (int i = 0; i < size / 2; i++) {
            ListNode* top = st.top();
            st.pop();
            ListNode* next = ptr->next;
            ptr->next = top;
            top->next = next;
            ptr = next;
        }
        ptr->next = nullptr;
    }

    // Time complexity O(n), space complexity O(1)
    void reorderList2(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;
        ListNode* fast = head;
        ListNode* slow = head;

        // find middle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2nd part head
        fast = slow->next;
        slow->next = nullptr;
        ListNode* part2 = reverseList(fast);
        ListNode* part1 = head;

        // interlace 1st and 2nd part
        while (part1 != nullptr && part2 != nullptr) {
            ListNode* next1 = part1->next;
            ListNode* next2 = part2->next;
            part1->next = part2;
            part2->next = next1;
            part1 = next1;
            part2 = next2;
        }
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

    vector<int> vectorizeList(ListNode* head) {
        vector<int> v;
        ListNode* ptr = head;
        while (ptr) {
            v.push_back(ptr->val);
            ptr = ptr->next;
        }
        return v;
    }
};

TEST(ListNode, Reorder1) {
    Solution sol;
    ListNode* head = nullptr;
    sol.insertNode(head, 1);
    sol.insertNode(head, 2);
    sol.insertNode(head, 3);
    sol.insertNode(head, 4);
    sol.reorderList(head);
    sol.displayList(head);
    vector<int> ans = {1, 4, 2, 3};

    ASSERT_EQ(sol.vectorizeList(head), ans);
}

TEST(ListNode, Reorder2) {
    Solution sol;
    ListNode* head = nullptr;
    sol.insertNode(head, 1);
    sol.insertNode(head, 2);
    sol.insertNode(head, 3);
    sol.insertNode(head, 4);
    sol.insertNode(head, 5);
    sol.reorderList(head);
    sol.displayList(head);
    vector<int> ans = {1, 5, 2, 4, 3};

    ASSERT_EQ(sol.vectorizeList(head), ans);
}
