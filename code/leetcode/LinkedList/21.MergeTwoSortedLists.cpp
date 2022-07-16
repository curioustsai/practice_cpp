/*
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.
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
    // iterative method
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode *dump, *ptr;
        dump = new ListNode();
        ptr = dump;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                ptr->next = list1;
                list1 = list1->next;
            } else {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }

        if (list1) ptr->next = list1;
        if (list2) ptr->next = list2;

        ptr = dump->next;
        delete dump;
        return ptr;
    }

    // recursive method
    ListNode* mergeTwoList(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        if (l1->val < l2->val) {
            l1->next = mergeTwoList(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoList(l2->next, l1);
            return l2;
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

    void displayList(ListNode* head) {
        ListNode* ptr = head;
        while (ptr) {
            cout << ptr->val << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

TEST(ListNode, Merge1) {
    Solution sol;
    ListNode *head1 = nullptr, *head2 = nullptr;
    ListNode* merged = nullptr;
    sol.insertNode(head1, 1);
    sol.insertNode(head1, 2);
    sol.insertNode(head1, 4);

    sol.insertNode(head2, 1);
    sol.insertNode(head2, 3);
    sol.insertNode(head2, 4);

    merged = sol.mergeTwoLists(head1, head2);

    ASSERT_EQ(merged->val, 1);
    ASSERT_EQ(merged->next->val, 1);
    ASSERT_EQ(merged->next->next->val, 2);
    ASSERT_EQ(merged->next->next->next->val, 3);
    ASSERT_EQ(merged->next->next->next->next->val, 4);
    ASSERT_EQ(merged->next->next->next->next->next->val, 4);
}
