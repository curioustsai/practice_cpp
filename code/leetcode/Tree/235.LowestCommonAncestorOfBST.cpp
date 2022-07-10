/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T 
that has both p and q as descendants (where we allow a node to be a descendant of itself).”
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
    // https://leetcode.com/problems/kth-smallest-element-in-a-bst/discuss/63673/4-Lines-in-C%2B%2B.
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if ((root->val > p->val) && (root->val > q->val)) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if ((root->val < p->val) && (root->val < q->val)) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
    // TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    //     if (!inTree(root, p) && !inTree(root, q)) return nullptr;

    //     // not in the same tree, return root
    //     // in the same tree, go either left or right
    //     // go left
    //     if (inTree(root->left, p) && inTree(root->left, q))
    //         return lowestCommonAncestor(root->left, p, q);
    //     else if (inTree(root->right, p) && inTree(root->right, q))
    //         return lowestCommonAncestor(root->right, p, q);
    //     else
    //         return root;
    // }

    // bool inTree(TreeNode *root, TreeNode *p) {
    //     if (root == p)
    //         return true;
    //     else if (root == nullptr)
    //         return false;
    //     else
    //         return inTree(root->left, p) || inTree(root->right, p);
    // }

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

TEST(LowestCommonAncestor, Example1) {
    Solution sol;
    TreeNode *root = nullptr;
    sol.insertNode(root, 6);
    sol.insertNode(root, 2);
    sol.insertNode(root, 8);
    sol.insertNode(root, 0);
    sol.insertNode(root, 4);
    sol.insertNode(root, 7);
    sol.insertNode(root, 9);
    sol.insertNode(root, 3);
    sol.insertNode(root, 5);

    ASSERT_EQ(sol.lowestCommonAncestor(root, root->left, root->right), root);
}

TEST(LowestCommonAncestor, Example2) {
    Solution sol;
    TreeNode *root = nullptr;
    sol.insertNode(root, 6);
    sol.insertNode(root, 2);
    sol.insertNode(root, 8);
    sol.insertNode(root, 0);
    sol.insertNode(root, 4);
    sol.insertNode(root, 7);
    sol.insertNode(root, 9);
    sol.insertNode(root, 3);
    sol.insertNode(root, 5);

    ASSERT_EQ(sol.lowestCommonAncestor(root, root->left, root->left->right), root->left);
}
