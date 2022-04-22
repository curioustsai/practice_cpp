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

void traverse_dfs(Node *tree) {
    if (!tree) { return; }

    // pre-order
    cout << tree->data << endl;
    traverse_dfs(tree->left);
    traverse_dfs(tree->right);
}

void findLevelLinkedLists(vector<list<Node *>> &res, Node *root) {
    list<Node *> li;
    li.push_back(root);
    res.push_back(li);
    int depth = 0;
    while (!res[depth].empty()) {
        list<Node *> l;
        list<Node *>::iterator iter;
        for (iter = res[depth].begin(); iter != res[depth].end(); iter++) {
            Node *ptr = *iter;
            if (ptr->left) l.push_back(ptr->left);
            if (ptr->right) l.push_back(ptr->right);
        }
        res.push_back(l);
        depth++;
    }
}

void printLevelLinkedLists(vector<list<Node *>> res) {
    vector<list<Node *>>::iterator iter;
    for (iter = res.begin(); iter != res.end(); iter++) {
        list<Node *> li = *iter;   //iter is a pointer to list<Node*>
        list<Node *>::iterator it; //it is a pointer to Node*
        for (it = li.begin(); it != li.end(); it++) {
            Node *ptr = *it;
            cout << ptr->data << " ";
        }
        cout << '\n';
    }
}

int main() {

    // int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int array[] = {1, 2, 3, 4, 5, 6, 7};

    Node *bst = create_bst(nullptr, array, 0, sizeof(array) / sizeof(array[0]) - 1);

    // traverse_dfs(bst);

    vector<list<Node *>> lists;
    findLevelLinkedLists(lists, bst);
    printLevelLinkedLists(lists);

    return 0;
}
