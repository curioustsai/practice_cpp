/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings.
There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

https://leetcode.com/problems/implement-trie-prefix-tree/
*/

#include <gtest/gtest.h>
#include <string>

using namespace std;

struct Node {
    bool isEnd;
    Node* child[26];

    Node() {
        isEnd = false;
        for (int i = 0; i < 26; i++) child[i] = nullptr;
    }

    Node(bool end) : isEnd(end) {
        for (int i = 0; i < 26; i++) child[i] = nullptr;
    }
};

class Trie {
public:
    Trie() { root = new Node(); }
    ~Trie() {
        releaseNode(root);
        root = nullptr;
    }

    void releaseNode(Node* root) {
        Node* ptr = root;
        for (int i = 0; i < 26; i++) {
            if (ptr->child[i] != nullptr) releaseNode(ptr->child[i]);
        }
        delete ptr;
    }

    void insert(string word) {
        Node* ptr = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (ptr->child[index] == nullptr) { ptr->child[index] = new Node; }
            ptr = ptr->child[index];
        }
        ptr->isEnd = true;
    }

    bool search(string word) {
        Node* ptr = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (ptr->child[index] == nullptr) return false;
            ptr = ptr->child[index];
        }
        return ptr->isEnd;
    }

    bool startsWith(string prefix) {
        Node* ptr = root;
        for (int i = 0; i < prefix.length(); i++) {
            int index = prefix[i] - 'a';
            if (ptr->child[index] == nullptr) return false;
            ptr = ptr->child[index];
        }
        return true;
    }

private:
    Node* root{nullptr};
};

TEST(Trie, Example1) {
    Trie* obj = new Trie();
    obj->insert("apple");
    ASSERT_EQ(obj->search("apple"), true);
    ASSERT_EQ(obj->search("app"), false);
    ASSERT_EQ(obj->startsWith("app"), true);
    obj->insert("app");
    ASSERT_EQ(obj->search("app"), true);
    obj->insert("hotdog");
    ASSERT_EQ(obj->startsWith("dog"), false);
}
