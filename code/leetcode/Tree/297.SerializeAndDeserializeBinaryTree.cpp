/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
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

//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/discuss/?currentPage=1&orderBy=most_votes&query=
class Solution {
public:
    string serialize(TreeNode *root) {
        if (root == nullptr) return "";

        ostringstream out;
        serialize_(root, out);
        return out.str();
    }

    void serialize_(TreeNode *root, ostringstream &out) {
        if (root) {
            out << root->val << ",";
            serialize_(root->left, out);
            serialize_(root->right, out);
        } else {
            out << "null,";
        }
    }

    TreeNode *deserialize(string data) {
        if (data.empty()) return nullptr;

        istringstream in(data);
        return deserialize_(in);
    }

    TreeNode *deserialize_(istringstream &in) {
        string val;
        getline(in, val, ',');
        if (val == "null") return nullptr;
        TreeNode *root = new TreeNode(stoi(val));
        root->left = deserialize_(in);
        root->right = deserialize_(in);
        return root;
    }

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

TEST(Serialize, Example1) {
    Solution sol;
    TreeNode *root = nullptr;

    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string s = sol.serialize(root);
    TreeNode *reconst = sol.deserialize(s);

    ASSERT_EQ(sol.isSameTree(root, reconst), true);

    sol.deleteTree(root);
    sol.deleteTree(reconst);
}

TEST(Serialize, Example2) {
    Solution sol;
    TreeNode *root = nullptr;

    string s = sol.serialize(root);
    TreeNode *reconst = sol.deserialize(s);

    ASSERT_EQ(sol.isSameTree(root, reconst), true);

    sol.deleteTree(root);
    sol.deleteTree(reconst);
}
