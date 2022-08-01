/*
Given the root of a binary tree, invert the tree, and return its root.

https://leetcode.com/problems/invert-binary-tree/
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
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr) return nullptr;
        TreeNode *root_inv = new TreeNode(root->val);
        root_inv->left = invertTree(root->right);
        root_inv->right = invertTree(root->left);

        return root_inv;
    }

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

TEST(InvertTree, Example1) {
    Solution sol;
    TreeNode *root = nullptr;
    root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    TreeNode *invert1 = sol.invertTree(root);
    TreeNode *invert2 = sol.invertTree(invert1);
    ASSERT_EQ(sol.isSameTree(root, invert2), true);
    sol.deleteTree(root);
    sol.deleteTree(invert1);
    sol.deleteTree(invert2);
}

TEST(InvertTree, Example2) {
    Solution sol;
    TreeNode *root = nullptr;

    sol.insertNode(root, 2);
    sol.insertNode(root, 1);
    sol.insertNode(root, 3);

    TreeNode *invert1 = sol.invertTree(root);
    TreeNode *invert2 = sol.invertTree(invert1);
    ASSERT_EQ(sol.isSameTree(root, invert2), true);
    sol.deleteTree(root);
    sol.deleteTree(invert1);
    sol.deleteTree(invert2);
}
