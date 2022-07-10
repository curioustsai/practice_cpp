/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

#include <gtest/gtest.h>

#include <iostream>
#include <queue>
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
    bool isValidBST(TreeNode *root) { return isValidBST(root, nullptr, nullptr); }
    bool isValidBST(TreeNode *root, TreeNode *minNode, TreeNode *maxNode) {
        if (root == nullptr) return true;
        if ((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val)) {
            return false;
        }
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
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

TEST(ValidBST, Example1) {
    Solution sol;
    TreeNode *root = nullptr;
    root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    ASSERT_EQ(sol.isValidBST(root), true);

    sol.deleteTree(root);
}

TEST(ValidBST, Example2) {
    Solution sol;
    TreeNode *root = nullptr;
    root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);

    ASSERT_EQ(sol.isValidBST(root), false);

    sol.deleteTree(root);
}
