#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    Node* left{nullptr};
    Node* right{nullptr};
    int data;

    Node(int val) : data(val) {}
};

void inorder(Node* tree) {
    if (tree == nullptr) return;
    inorder(tree->left);
    cout << tree->data << endl;
    inorder(tree->right);
}

void deleteTree(Node* tree) {
    if (tree == nullptr) return;
    deleteTree(tree->left);
    deleteTree(tree->right);

    delete tree;
    tree = nullptr;
}

void serializeTree(Node* n, FILE* fp) {
    if (n == nullptr) {
        fprintf(fp, "%d ", INT32_MAX);
        return;
    }

    fprintf(fp, "%d ", n->data);
    serializeTree(n->left, fp);
    serializeTree(n->right, fp);
}

void deserializeTree(Node*& n, FILE* fp) {
    int val;
    if (!fscanf(fp, "%d ", &val) || val == INT32_MAX) return;

    n = new Node(val);
    deserializeTree(n->left, fp);
    deserializeTree(n->right, fp);

    return;
}

Node* create_bst(vector<int>& arr, int start, int end) {
    if (start > end) return nullptr;

    Node* tree;
    int mid = (start + end) / 2;
    tree = new Node(arr[mid]);
    tree->left = create_bst(arr, start, mid - 1);
    tree->right = create_bst(arr, mid + 1, end);

    return tree;
}

class TreeTest : public testing::Test {
protected:
    void SetUp() override {
        vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        bst = create_bst(v, 0, v.size() - 1);
    }

    void TearDown() override { deleteTree(bst); }

    Node* bst;
};

TEST_F(TreeTest, inorder) { inorder(bst); }
TEST_F(TreeTest, serialize) {
    FILE* fw = fopen("serialize.txt", "w");
    serializeTree(bst, fw);
    inorder(bst);
    fclose(fw);

    FILE* fr = fopen("serialize.txt", "r");
    Node* nn;
    deserializeTree(nn, fr);
    fclose(fr);
    inorder(nn);
}
