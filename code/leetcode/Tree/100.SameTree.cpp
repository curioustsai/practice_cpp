/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

https://leetcode.com/problems/same-tree/
*/

#include <gtest/gtest.h>

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == nullptr || q == nullptr) return (p == q);
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    int maxDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return max(left, right) + 1;
    }

    void insertNode(TreeNode *&head, int val) {
        if (head == nullptr)
            head = new TreeNode(val);
        else {
            if (val < head->val) {
                insertNode(head->left, val);
            } else {
                insertNode(head->right, val);
            }
        }
    }

    void deleteTree(TreeNode *&head) {
        if (head == nullptr) return;
        deleteTree(head->left);
        deleteTree(head->right);
        delete head;
        head = nullptr;
    }

    void preorder(TreeNode *head) {
        if (head == nullptr) return;
        cout << head->val << endl;
        preorder(head->left);
        preorder(head->right);
    }
};

TEST(SameTree, Example1) {
    Solution sol;
    TreeNode *root1 = nullptr, *root2 = nullptr;
    sol.insertNode(root1, 1);
    sol.insertNode(root1, 2);
    sol.insertNode(root1, 3);
    sol.insertNode(root2, 1);
    sol.insertNode(root2, 2);
    sol.insertNode(root2, 3);

    ASSERT_EQ(sol.isSameTree(root1, root2), true);
    sol.deleteTree(root1);
    sol.deleteTree(root2);
}

TEST(SameTree, Example2) {
    Solution sol;
    TreeNode *root1 = nullptr;
    TreeNode *root2 = nullptr;

    root1 = new TreeNode(1);
    root1->left = new TreeNode(2);

    root2 = new TreeNode(1);
    root2->right = new TreeNode(2);

    ASSERT_EQ(sol.isSameTree(root1, root2), false);
    sol.deleteTree(root1);
    sol.deleteTree(root2);
}

TEST(SameTree, Example3) {
    Solution sol;
    TreeNode *root1 = nullptr;
    TreeNode *root2 = nullptr;

    root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(1);

    root2 = new TreeNode(1);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(2);

    ASSERT_EQ(sol.isSameTree(root1, root2), false);
    sol.deleteTree(root1);
    sol.deleteTree(root2);
}
