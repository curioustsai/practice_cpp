/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
    // utilize inorder traverse, more intuitive
    int kthSmallest2(TreeNode *root, int k) {
        int result;
        helper(root, k, result);
        return result;
    }

    void helper(TreeNode *root, int &k, int &result) {
        if (!root) return;

        helper(root->left, k, result);
        k--;
        if (k == 0) {
            result = root->val;
            return;
        }
        helper(root->right, k, result);
    }
    // https://leetcode.com/problems/kth-smallest-element-in-a-bst/discuss/63673/4-Lines-in-C%2B%2B.
    int kthSmallest(TreeNode *root, int k) { return find(root, k); }

    int find(TreeNode *root, int &k) {
        if (root == nullptr) return INT32_MIN;

        int x = find(root->left, k);
        if (k == 0) {
            return x;
        } else if (k == 1) {
            k--;
            return root->val;
        } else {
            k--;
            return find(root->right, k);
        }
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

TEST(KthSmallest, Example1) {
    Solution sol;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(4);

    ASSERT_EQ(sol.kthSmallest2(root, 1), 1);
}

TEST(KthSmallest, Example2) {
    Solution sol;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(6);

    ASSERT_EQ(sol.kthSmallest2(root, 3), 3);
}
