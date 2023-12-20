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
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode();
        dummy->next = head;

        //get len
        int length = 0;
        ListNode* ptr = head;
        while (ptr) {
            length++;
            ptr = ptr->next;
        }
        ListNode* prev = dummy;
        ListNode* curr = dummy->next;
        for (int i = 0; i < length / k; i++) {
            for (int j = 1; j < k; j++) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            prev = curr;
            curr = curr->next;
        }

        ptr = dummy->next;
        delete dummy;
        return ptr;

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

