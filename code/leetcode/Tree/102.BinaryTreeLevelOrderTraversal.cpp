/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;

        queue<TreeNode *> q, q_next;
        q_next.push(root);

        while (!q_next.empty()) {
            swap(q, q_next);
            vector<int> v;
            while (!q.empty()) {
                TreeNode *n = q.front();
                q.pop();
                v.push_back(n->val);

                if (n->left != nullptr) q_next.push(n->left);
                if (n->right != nullptr) q_next.push(n->right);
            }
            res.push_back(v);
        }

        return res;
    }

    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr) return nullptr;
        TreeNode *root_inv = new TreeNode(root->val, root->right, root->left);
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

TEST(BinaryTreeLevelOrderTraversal, Example1) {
    Solution sol;
    TreeNode *root = nullptr;
    root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> res = sol.levelOrder(root);
    vector<vector<int>> ans = {{3}, {9, 20}, {15, 7}};
    ASSERT_EQ(res, ans);

    sol.deleteTree(root);
}
