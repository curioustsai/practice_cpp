/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings.
There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

https://leetcode.com/problems/add-and-search-word-data-structure-design/
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

class WordDictionary {
public:
    WordDictionary() { root = new Node(); }
    ~WordDictionary() {
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

    void addWord(string word) {
        Node* ptr = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (ptr->child[index] == nullptr) { ptr->child[index] = new Node; }
            ptr = ptr->child[index];
        }
        ptr->isEnd = true;
    }

    bool search(string word) { return search(word, root); }

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

    bool search(string word, Node* root) {
        Node* ptr = root;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] != '.') {
                int index = word[i] - 'a';
                if (ptr->child[index] == nullptr) return false;
                ptr = ptr->child[index];
            } else {
                for (int j = 0; j < 26; j++) {
                    if (ptr->child[j] && search(word.substr(i + 1), ptr->child[j])) return true;
                }
            }
        }
        return ptr->isEnd;
    }
};

TEST(WordDictionary, Example1) {
    WordDictionary* obj = new WordDictionary();
    obj->addWord("bad");
    obj->addWord("dad");
    obj->addWord("mad");
    ASSERT_EQ(obj->search("pad"), false);
    ASSERT_EQ(obj->search("bad"), true);
    ASSERT_EQ(obj->search(".ad"), true);
    ASSERT_EQ(obj->search("b.."), true);
}

TEST(WordDictionary, Example2) {
    WordDictionary* obj = new WordDictionary();
    obj->addWord("a");
    obj->addWord("a");
    ASSERT_EQ(obj->search("."), true);
    ASSERT_EQ(obj->search("a"), true);
    ASSERT_EQ(obj->search("aa"), false);
    ASSERT_EQ(obj->search("a"), true);
    ASSERT_EQ(obj->search(".a"), true);
    ASSERT_EQ(obj->search("a."), true);
}
