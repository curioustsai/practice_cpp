#pragma once

// namespace dsa {
// template <class T>
class BSTNode {
public:
    BSTNode(int data) : _data(data) {
        leftNode = nullptr;
        rightNode = nullptr;
    };

    // Returns a new node for our BST
    BSTNode* GetNewNode(int value);

    // Returns true if given value is in our tree
    bool Search(BSTNode* node, int value);

    // Frees memory allocated for the tree.
    void DeleteTree(BSTNode* node);

    // Returns the minimum value stored in the tree,
    // or -1 if tree is empty
    int GetMin(BSTNode* node);

    // Returns the maximum value stored in the tree,
    // or -1 if tree is empty
    int GetMax(BSTNode* node);

    // Returns height of the tree, 0 if empty
    int GetHeight(BSTNode* node);

    // Print out the items in the tree in level order
    void PrintBFS(BSTNode* node);

    // Print out the items in the tree in order (inorder)
    void PrintInOrder(BSTNode* node);

    // Returns true if tree is a binary search tree
    bool IsBinarySearchTree(BSTNode* node);

    // Returns true if all items in the given tree are between the given values
    bool IsBetween(BSTNode* node, int min, int max);

    // Delete a specific node from the tree
    BSTNode* DeleteValue(BSTNode* node, int value);

    // Returns the node in the tree with the minimum value
    BSTNode* GetMinNode(BSTNode* node);

    // Returns the in-order successor of the given value
    BSTNode* GetSuccessor(BSTNode* node, int value);

private:
    int _data;
    BSTNode* leftNode;
    BSTNode* rightNode;
};
// }  // namespace dsa

// template class dsa::BSTNode<int>;
