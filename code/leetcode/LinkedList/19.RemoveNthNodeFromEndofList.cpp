/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.
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
    // Dummy node trick
    // https://leetcode.com/problems/remove-nth-node-from-end-of-list/discuss/8804/Simple-Java-solution-in-one-pass
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode(0);
        start->next = head;
        ListNode* fast = start;
        ListNode* slow = start;

        for (int i = 1; i <= n; i++) { fast = fast->next; }

        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* temp = slow->next;
        slow->next = slow->next->next;

        delete temp;
        temp = start->next;
        delete start;

        return temp;
    }
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     if (head == nullptr) return nullptr;
    //     ListNode* ptr1 = head;
    //     ListNode* ptr2 = head;
    //     ListNode* prev = nullptr;

    //     int count = 1;
    //     while (count < n) {
    //         if (ptr2 == nullptr) return nullptr;
    //         ptr2 = ptr2->next;
    //         count++;
    //     }

    //     while (ptr2->next != nullptr) {
    //         prev = ptr1;
    //         ptr1 = ptr1->next;
    //         ptr2 = ptr2->next;
    //     }

    //     if (ptr1 != head) {
    //         prev->next = ptr1->next;
    //     } else {
    //         head = nullptr;
    //     }
    //     delete ptr1;

    //     return head;
    // }

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

TEST(ListNode, RemoveNthFromEnd1) {
    Solution sol;
    ListNode* head = nullptr;
    sol.insertNode(head, 1);
    sol.insertNode(head, 2);
    sol.insertNode(head, 3);
    sol.insertNode(head, 4);
    sol.insertNode(head, 5);
    int n = 2;

    ListNode* ret = sol.removeNthFromEnd(head, n);
    vector<int> ans = {1, 2, 3, 5};
    ASSERT_EQ(sol.vectorizeList(ret), ans);
}

TEST(ListNode, RemoveNthFromEnd2) {
    Solution sol;
    ListNode* head = nullptr;
    sol.insertNode(head, 1);
    int n = 1;

    ListNode* ret = sol.removeNthFromEnd(head, n);
    vector<int> ans = {};
    ASSERT_EQ(sol.vectorizeList(ret), ans);
}

TEST(ListNode, RemoveNthFromEnd3) {
    Solution sol;
    ListNode* head = nullptr;
    sol.insertNode(head, 1);
    sol.insertNode(head, 2);
    int n = 1;

    ListNode* ret = sol.removeNthFromEnd(head, n);
    vector<int> ans = {1};
    ASSERT_EQ(sol.vectorizeList(ret), ans);
}

TEST(ListNode, RemoveNthFromEnd4) {
    Solution sol;
    ListNode* head = nullptr;
    sol.insertNode(head, 1);
    sol.insertNode(head, 2);
    int n = 2;

    ListNode* ret = sol.removeNthFromEnd(head, n);
    vector<int> ans = {2};
    ASSERT_EQ(sol.vectorizeList(ret), ans);
}
