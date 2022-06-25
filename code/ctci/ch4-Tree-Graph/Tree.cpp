// Collection of tree practice
// TODO:
// FindSuccessor

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

Node* InsertNode(Node* root, int data) {
    if (root == nullptr) return new Node(data);
    if (root->data > data) {
        root->left = InsertNode(root->left, data);
    } else {
        root->right = InsertNode(root->right, data);
    }
    return root;
}

// input: tree root and key value
// output: the root after remove value
Node* DeleteNode(Node* root, int value) {
    if (root == nullptr) return nullptr;

    if (root->data > value) {
        return DeleteNode(root->left, value);
    } else if (root->data < value) {
        return DeleteNode(root->right, value);
    }

    // hit the node
    if (root->right == nullptr) {
        // condition 1. only left child
        Node* temp = root->left;
        free(root);
        return temp;
    } else if (root->left == nullptr) {
        // condition 2. only right child
        Node* temp = root->right;
        free(root);
        return temp;
    } else {
        // conditoin 3. both left and right exist

        // find the mimum value as successor
        Node* succParanet = root;
        Node* succ = root->right;
        while (succ->left != nullptr) {
            succParanet = succ;
            succ = succ->left;
        }

        // link node before delete
        if (succParanet != root) {
            //  successorParent(root)
            //                 \
            //                  Node
            //                /        \
            //       successorParent    Node
            //         /         \
            //      successor   Node
            //      /     \
            //   nullptr successor->right
            succParanet->left = succ->right;
        } else {
            //  successorParent(root)
            //                 \
            //               successor
            //                /      \
            //              nullptr   successor->right
            succParanet->right = succ->right;
        }
        // replace root with successor
        root->data = succ->data;
        delete succ;
        return root;
    }
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

void DisplayTrtee(Node* tree) {
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
}

class TreeTest : public testing::Test {
protected:
    void SetUp() override {
        vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        bst = create_bst(v, 0, v.size() - 1);

        bst2 = InsertNode(bst2, 8);
        bst2 = InsertNode(bst2, 3);
        bst2 = InsertNode(bst2, 10);
        bst2 = InsertNode(bst2, 1);
        bst2 = InsertNode(bst2, 6);
        bst2 = InsertNode(bst2, 14);
        bst2 = InsertNode(bst2, 4);
        bst2 = InsertNode(bst2, 7);
        bst2 = InsertNode(bst2, 13);
    }

    void TearDown() override {
        DeleteTree(bst);
        DeleteTree(bst2);
    }

    Node* bst{nullptr};
    Node* bst2{nullptr};
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

TEST_F(TreeTest, isBalance) {

    DisplayTrtee(bst2);

    ASSERT_EQ(isBalance(bst2), false);
}

TEST_F(TreeTest, DeleteNode) {
    DisplayTrtee(bst2);
    DeleteNode(bst2, 6);
    DisplayTrtee(bst2);
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
