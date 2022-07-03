/*
Diffculty: hard

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.
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
    // https://leetcode.com/problems/merge-k-sorted-lists/discuss/10531/Sharing-my-straightforward-C%2B%2B-solution-without-data-structure-other-than-vector
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        int len = lists.size();
        while (len > 1) {
            for (int i = 0; i < len / 2; i++) {
                lists[i] = mergeTwoList(lists[i], lists[len - 1 - i]);
            }
            len = (len + 1) / 2;
        }

        return lists.front();
    }

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

TEST(ListNode, MergeKSorted1) {
    Solution sol;
    ListNode *head1 = nullptr, *head2 = nullptr, *head3 = nullptr;
    ListNode* merged = nullptr;
    sol.insertNode(head1, 1);
    sol.insertNode(head1, 4);
    sol.insertNode(head1, 5);

    sol.insertNode(head2, 1);
    sol.insertNode(head2, 3);
    sol.insertNode(head2, 4);

    sol.insertNode(head3, 2);
    sol.insertNode(head3, 6);

    vector<ListNode*> lists;
    lists.push_back(head1);
    lists.push_back(head2);
    lists.push_back(head3);

    merged = sol.mergeKLists(lists);

    vector<int> ans = {1, 1, 2, 3, 4, 4, 5, 6};
    ASSERT_EQ(sol.vectorizeList(merged), ans);
}

TEST(ListNode, MergeKSorted2) {
    Solution sol;
    vector<ListNode*> lists;
    ListNode* merged = sol.mergeKLists(lists);

    ASSERT_EQ(merged, nullptr);
}

TEST(ListNode, MergeKSorted3) {
    Solution sol;
    vector<ListNode*> lists;
    lists.push_back(nullptr);
    ListNode* merged = sol.mergeKLists(lists);

    ASSERT_EQ(merged, nullptr);
}
