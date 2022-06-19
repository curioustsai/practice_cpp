// Collection of tree practice
// TODO:
// FindSuccessor
// RemoveNode

#include <gtest/gtest.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    Node* left{nullptr};
    Node* right{nullptr};
    int data;

    Node(int val) : data(val) {}
};

void Preorder(Node* tree) {
    if (tree == nullptr) return;
    cout << tree->data << endl;
    Preorder(tree->left);
    Preorder(tree->right);
}

void Inorder(Node* tree) {
    if (tree == nullptr) return;
    Inorder(tree->left);
    cout << tree->data << endl;
    Inorder(tree->right);
}

void Postorder(Node* tree) {
    if (tree == nullptr) return;
    Inorder(tree->left);
    Inorder(tree->right);
    cout << tree->data << endl;
}

void DeleteTree(Node* tree) {
    if (tree == nullptr) return;
    DeleteTree(tree->left);
    DeleteTree(tree->right);

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

vector<vector<Node*>> DepthIter(Node* tree) {
    vector<vector<Node*>> list;
    vector<Node*> l;

    l.push_back(tree);
    list.push_back(l);
    int level = 0;

    while (list[level].size() != 0) {
        queue<Node*> q;
        for (Node* n : list[level]) { q.push(n); }
        vector<Node*> child;

        while (!q.empty()) {
            Node* n = q.front();
            q.pop();
            if (n->left != nullptr) child.push_back(n->left);
            if (n->right != nullptr) child.push_back(n->right);
        }
        list.push_back(child);
        level++;
    }
    list.pop_back();

    return list;
}

vector<vector<Node*>> DepthIter2(Node* tree) {
    vector<vector<Node*>> list;
    vector<Node*> l;

    l.push_back(tree);
    list.push_back(l);
    int level = 0;

    while (list[level].size() != 0) {
        queue<Node*> q;
        for (Node* n : list[level]) { q.push(n); }
        vector<Node*> child;

        while (!q.empty()) {
            Node* n = q.front();
            q.pop();
            if (n != nullptr) {
                child.push_back(n->left);
                child.push_back(n->right);
            }
        }
        bool bAllNullptr = true;
        for (Node* n : child) {
            if (n != nullptr) bAllNullptr = false;
        }
        if (bAllNullptr) break;
        list.push_back(child);
        level++;
    }

    return list;
}

int GetHeight(Node* tree) {
    if (tree == nullptr) return 0;
    return std::max(GetHeight(tree->left), GetHeight(tree->right)) + 1;
}

int checkHeight(Node* tree) {
    if (tree == nullptr) return -1;

    int leftHeight = checkHeight(tree->left);
    int rightHeight = checkHeight(tree->right);

    if (std::abs(leftHeight - rightHeight) > 1)
        return INT32_MIN;
    else
        return std::max(leftHeight, rightHeight) + 1;
}

int isBalance(Node* tree) { return checkHeight(tree) != INT32_MIN; }

class TreeTest : public testing::Test {
protected:
    void SetUp() override {
        vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        bst = create_bst(v, 0, v.size() - 1);
    }

    void TearDown() override { DeleteTree(bst); }

    Node* bst;
};

TEST_F(TreeTest, inorder) { Inorder(bst); }
TEST_F(TreeTest, serialize) {
    FILE* fw = fopen("serialize.txt", "w");
    serializeTree(bst, fw);
    Inorder(bst);
    fclose(fw);

    FILE* fr = fopen("serialize.txt", "r");
    Node* nn;
    deserializeTree(nn, fr);
    fclose(fr);
    Inorder(nn);
}

TEST(tree, isBalance) {
    Node* tree = new Node(3);
    tree->left = new Node(1);
    tree->left->right = new Node(2);
    tree->left->right->left = new Node(0);
    tree->right = new Node(4);

    vector<vector<Node*>> list = DepthIter2(tree);
    for (vector<Node*> l : list) {
        for (Node* n : l) {
            if (n != nullptr)
                cout << n->data << ", ";
            else
                cout << "np, ";
        }
        cout << endl;
    }

    ASSERT_EQ(isBalance(tree), false);
}

TEST(tree, DepthIter) {
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    Node* bst = create_bst(v, 0, v.size() - 1);
    cout << "Height: " << GetHeight(bst) << endl;

    vector<vector<Node*>> list = DepthIter2(bst);

    for (vector<Node*> l : list) {
        for (Node* n : l) {
            if (n != nullptr)
                cout << n->data << ", ";
            else
                cout << "np, ";
        }
        cout << endl;
    }
}

// TEST(tree, create_bst) {
//     vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8};
//     Node* bst = create_bst(v, 0, v.size() - 1);

//     Preorder(bst);
// }

// TEST(Tree, Preorder) {
//     Node* tree = new Node(2);
//     tree->left = new Node(4);
//     tree->right = new Node(6);

//     Preorder(tree);
// }

// TEST(Tree, Inorder) {
//     Node* tree = new Node(2);
//     tree->left = new Node(4);
//     tree->right = new Node(6);

//     Inorder(tree);
// }

// TEST(Tree, Postorder) {
//     Node* tree = new Node(2);
//     tree->left = new Node(4);
//     tree->right = new Node(6);

//     Postorder(tree);
// }
