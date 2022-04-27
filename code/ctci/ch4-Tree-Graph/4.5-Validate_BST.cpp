/*
 * Valide BST
 */

#include <iostream>
#include <list>
#include <vector>

using namespace std;
struct Node {
    Node *left;
    Node *right;
    int data;

    Node(int value) : data(value){};
};

Node *create_bst(Node *tree, int arr[], int leftpoint, int rightpoint) {
    if (leftpoint > rightpoint) return nullptr;

    int midpoint = (leftpoint + rightpoint) / 2;

    Node *node = new Node(arr[midpoint]);
    node->left = create_bst(node, arr, leftpoint, midpoint - 1);
    node->right = create_bst(node, arr, midpoint + 1, rightpoint);

    return node;
}

bool isBST(Node *root) {
    if (root == nullptr) return true;

    if (root->left != nullptr && root->left->data > root->data) return false;
    if (root->right != nullptr && root->right->data < root->data) return false;
    if (!isBST(root->left) || !isBST(root->right)) return false;

    return true;
}

int main() {

    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int array[] = {1, 2, 3, 4, 5, 6, 7};

    Node *bst = create_bst(nullptr, array, 0, sizeof(array) / sizeof(array[0]) - 1);

    cout << "is binary search tree: " << boolalpha << isBST(bst) << endl;

    return 0;
}
