/*
 * Check if a tree is balanced
 * isBalanced if left height and right height of root is less than 1
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

int height(Node* root) {
    if (root->left == nullptr && root->right == nullptr) return 1;

    if (root->left == nullptr) {
        return height(root->right) + 1;
    } else if (root->right == nullptr){
        return height(root->left) + 1;
    } else {
        return std::max(height(root->left), height(root->right)) + 1;
    }
}

bool isBalance(Node *root) {
    // TODO: tackle null cases later
    int left_height = height(root->left);
    int right_height = height(root->right);

    return (abs(left_height- right_height) <= 1);
}


int main() {

    // int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int array[] = {1, 2, 3, 4, 5, 6, 7};

    Node *bst = create_bst(nullptr, array, 0, sizeof(array) / sizeof(array[0]) - 1);

    cout << "is balanced " << boolalpha << isBalance(bst) << endl;

    return 0;
}
