/*
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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

TEST(MaxDepthOfBinaryTree, Example1) {
    Solution sol;
    TreeNode *head = nullptr;
    sol.insertNode(head, 3);
    sol.insertNode(head, 1);
    sol.insertNode(head, 7);
    sol.insertNode(head, 15);
    sol.insertNode(head, 6);

    ASSERT_EQ(sol.maxDepth(head), 3);
    sol.deleteTree(head);
}

TEST(MaxDepthOfBinaryTree, Example2) {
    Solution sol;
    TreeNode *head = nullptr;
    sol.insertNode(head, 1);
    sol.insertNode(head, 2);

    ASSERT_EQ(sol.maxDepth(head), 2);
    sol.deleteTree(head);
}
