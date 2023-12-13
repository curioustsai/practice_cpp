/*
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
*/

#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;

        Node* org = head;
        while (org != nullptr) {
            Node* copy = new Node(org->val);
            m[org] = copy;
            org = org->next;
        }

        org = head;
        while (org != nullptr) {
            m[org]->next = m[org->next];
            m[org]->random = m[org->random];
            org = org->next;
        }

        return m[head];
    }
};
