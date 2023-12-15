#include <gtest/gtest.h>

#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};

class Solution {
    string serialized(TreeNode* node) {
        ostringstream osstream;

        serialzed_(node, osstream);

        return osstream.str();
    }

    void serialzed_(TreeNode* node, ostringstream& osstream) {
        if (node == nullptr) {
            osstream << "null ";
            return;
        }
        osstream << node->val << " ";

        serialzed_(node->left, osstream);
        serialzed_(node->right, osstream);
    }

    TreeNode* deserialize(string str){
        if (str.empty()) return nullptr;

        istringstream isstream(str);
        return deserialize_(isstream);
    }

    TreeNode* deserialize_(istringstream& isstream) {
        string sval;
        isstream >> sval;
        if (sval == "null") return nullptr;

        int val = stoi(sval);
        TreeNode* node = new TreeNode(val);
        node->left = deserialize_(isstream);
        node->right = deserialize_(isstream);

        return node;
    }

};

TEST(SerializeTree, Example1) {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(1);
}
