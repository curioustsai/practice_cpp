#include <iostream>
#include <queue>
#include <list>

using namespace std;

struct Node {
    Node *left{nullptr};
    Node *right{nullptr};
    int data;
    Node(int d) : data(d) {}
};

Node *create_bst(int *array, int leftpoint, int rightpoint) {
    if (leftpoint > rightpoint) { return nullptr; }

    int midpoint = (leftpoint + rightpoint) / 2;

    Node *tree = new Node(array[midpoint]);
    tree->left = create_bst(array, leftpoint, midpoint - 1);
    tree->right = create_bst(array, midpoint + 1, rightpoint);

    return tree;
}

void traverse(Node *tree) {
    if (!tree) return;
    cout << tree->data << endl;
    traverse(tree->left);
    traverse(tree->right);
}

void traverse_bfs(Node *tree) {
    queue<Node *> q;
    q.push(tree);

    while (!q.empty()) {
        Node *p = q.front();
        q.pop();
        cout << p->data << endl;
        if (p->left) q.push(p->left);
        if (p->right) q.push(p->right);
    }
}


int main() {
    // int array[] = {1, 2, 3, 4, 5, 6, 7};

    /*
     *     4
     *    / \
     *   2   6
     *  / \ / \
     * 1  3 5  7
     *
     */

    int array[] = {0, 1, 2, 3, 4, 5};

    /*
     *    2
     *   / \
     *  0    4
     *   \  / \
     *   1 3  5
     */

    Node *tree = create_bst(array, 0, sizeof(array) / sizeof(array[0]) - 1);
    traverse(tree);
    traverse_bfs(tree);

    return 0;
}
