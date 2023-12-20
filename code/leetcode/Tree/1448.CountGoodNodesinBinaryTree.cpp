/*
* https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/
*/

#include <gtest/gtest.h>

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
    int goodNodes(TreeNode* root) {
        int result = 0;
        dfs(root, root->val, result);

        return result;
    }
private:
    void dfs(TreeNode* root, int maxvalue, int& result) {
        if (root == nullptr)
            return;
        
        if (root->val >= maxvalue) {
            result++;
            maxvalue = root->val;
        }
        dfs(root->left, maxvalue, result);
        dfs(root->right, maxvalue, result);
    }
};
