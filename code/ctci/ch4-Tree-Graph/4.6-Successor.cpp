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

Node *findSuccessor(Node *root) {
    if (root == nullptr) return nullptr;
    Node *successor = nullptr;

    if (root->left) {
        // find the most right node
        successor = root->left;
        while (successor->right) { successor = successor->right; }
    } else if (root->right) {
        // find the most left leaf node
        successor = root->right;
        while (successor->left) { successor = successor->left; }
    }

    return successor;
}

int main() {

    // int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int array[] = {1, 2, 3, 4, 5, 6, 7};

    Node *bst = create_bst(nullptr, array, 0, sizeof(array) / sizeof(array[0]) - 1);

    Node *successor = findSuccessor(bst);

    if (successor) cout << "the successor data is  " << successor->data << endl;

    return 0;
}
