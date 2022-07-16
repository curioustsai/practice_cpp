/*
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

#include <gtest/gtest.h>

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        return build(preorder, inorder, rootIdx, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& rootIdx, int left,
                    int right) {
        if (left > right) return NULL;
        int pivot = left; // find the root from inorder
        while (inorder[pivot] != preorder[rootIdx]) pivot++;

        rootIdx++;
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        newNode->left = build(preorder, inorder, rootIdx, left, pivot - 1);
        newNode->right = build(preorder, inorder, rootIdx, pivot + 1, right);
        return newNode;
    }

    void insertNode(TreeNode*& head, int val) {
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

    void deleteTree(TreeNode*& head) {
        if (head == nullptr) return;
        deleteTree(head->left);
        deleteTree(head->right);
        delete head;
        head = nullptr;
    }

    void preorder(TreeNode* head) {
        if (head == nullptr) return;
        cout << head->val << endl;
        preorder(head->left);
        preorder(head->right);
    }
};

TEST(BuildTree, Example1) {
    Solution sol;
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode* root = sol.buildTree(preorder, inorder);
    sol.preorder(root);
}
