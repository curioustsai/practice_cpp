/*
* Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
* k is a positive integer and is less than or equal to the length of the linked list.
* If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is. 
* You may not alter the values in the list's nodes, only nodes themselves may be changed.
*
* https://leetcode.com/problems/reverse-nodes-in-k-group/description/
*
*/

#include <gtest/gtest.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// https://leetcode.com/problems/reverse-nodes-in-k-group/solutions/523641/c-iterative-solution-recursive-solution/
class Solution {
public:
    // space complexity O(n)
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cursor = head;
        for (int i = 0; i < k; i++) {
            if (cursor == nullptr) return head;
            cursor = cursor->next;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;
        for (int i = 0; i < k; i++) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }

    // space complexity O(1)
    ListNode* reverseKGroupIterative(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* before = dummy;
        ListNode* after = head;
        ListNode* curr = nullptr;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;

        while (true) {
            ListNode* cursor = after;
            for (int i = 0; i < k; i++) {
                if (cursor == nullptr) return dummy->next;
                cursor = cursor->next;
            }
            curr = after;
            prev = before;
            for (int i = 0; i < k; i++) {
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            after->next = curr;
            before->next = prev;
            before = after;
            after = curr;
        }
    }
};

TEST(ReverseKGroup, Examp1) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    sol.reverseKGroup(head, 2);
}
