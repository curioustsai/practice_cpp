/*
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.
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
    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        if (root == nullptr) return root == subRoot;
        return isSameTree(root, subRoot) || isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
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

TEST(Subtree, Example1) {
    Solution sol;
    TreeNode *root = nullptr;
    root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    TreeNode *subtree = nullptr;
    subtree = new TreeNode(4);
    subtree->left = new TreeNode(1);
    subtree->right = new TreeNode(2);

    ASSERT_EQ(sol.isSubtree(root, subtree), true);

    sol.deleteTree(root);
    sol.deleteTree(subtree);
}

TEST(Subtree, Example2) {
    Solution sol;
    TreeNode *root = nullptr;
    root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(0);

    TreeNode *subtree = nullptr;
    subtree = new TreeNode(4);
    subtree->left = new TreeNode(1);
    subtree->right = new TreeNode(2);

    ASSERT_EQ(sol.isSubtree(root, subtree), false);

    sol.deleteTree(root);
    sol.deleteTree(subtree);
}

TEST(Subtree, Example3) {
    Solution sol;
    TreeNode *root = nullptr;
    root = new TreeNode(1);
    root->left = new TreeNode(1);

    TreeNode *subtree = nullptr;
    subtree = new TreeNode(1);

    ASSERT_EQ(sol.isSubtree(root, subtree), true);

    sol.deleteTree(root);
    sol.deleteTree(subtree);
}
