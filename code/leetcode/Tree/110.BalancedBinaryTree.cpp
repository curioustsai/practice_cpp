/*
 * Given a binary tree, determine if it is height-balanced .
 * https://leetcode.com/problems/balanced-binary-tree/description/
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
    bool isBalanced(TreeNode* root) {
        int height = INT32_MIN;
        return isBalanced(root, height);
    }

    bool isBalanced(TreeNode* root, int& height) {
        if (root == nullptr) {
            height = -1;
            return true;
        }

        int lheight, rheight;
        if (!isBalanced(root->left, lheight) || !isBalanced(root->right, rheight))
          return false;

        if (abs(lheight-rheight) > 1) 
            return false;

        height = max(lheight, rheight) + 1;
        return true;
    }
};
