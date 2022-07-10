/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them.
A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any non-empty path.
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
    // https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/603072/C%2B%2B-solution-O(n)-with-detailed-explanation
    int max_sum = INT32_MIN;
    int max_gain(TreeNode *root) {
        if (!root) return 0;
        int l = max(max_gain(root->left), 0);
        int r = max(max_gain(root->right), 0);
        int new_price = root->val + l + r;
        max_sum = max(max_sum, new_price);
        return root->val + max(l, r);
    }
    int maxPathSum(TreeNode *root) {
        max_gain(root);
        return max_sum;
    }
};

TEST(MaxPathSum, Example1) {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution sol;
    ASSERT_EQ(sol.maxPathSum(root), 6);
}

TEST(MaxPathSum, Example2) {
    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    ASSERT_EQ(sol.maxPathSum(root), 42);
}
