#include <gtest/gtest.h>
#include <iostream>
#include <string>

constexpr int ALPHA_NUMBER = 26;

class TrieNode {
private:
    TrieNode *child[ALPHA_NUMBER];
    bool isEndofWord;

public:
    TrieNode() {
        isEndofWord = false;
        for (int i = 0; i < ALPHA_NUMBER; i++) { child[i] = nullptr; }
    }

    void insert(std::string key) {
        TrieNode *pCrawl = this;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!pCrawl->child[index]) { pCrawl->child[index] = new TrieNode(); }

            pCrawl = pCrawl->child[index];
        }
        pCrawl->isEndofWord = true;
    }

    bool search(std::string key) {
        TrieNode *pCrawl = this;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!pCrawl->child[index]) return false;
            pCrawl = pCrawl->child[index];
        }
        return pCrawl->isEndofWord;
    }

    bool remove(std::string key) {
        TrieNode *pCrawl = this;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!pCrawl->child[index]) return false;
            pCrawl = pCrawl->child[index];
        }
        pCrawl->isEndofWord = false;
        return true;
    }
};

void ShowExistWord(TrieNode *root, std::string word) {
    std::cout << "check word in the tries: " << word << " " << std::boolalpha << root->search(word)
              << std::endl;
}

TEST(Tries, main) {
    TrieNode *root = new TrieNode();

    std::string words[] = {"apple", "banana", "orange"};

    for (std::string word : words) { root->insert(word); }

    ShowExistWord(root, "apple");
    ShowExistWord(root, "banna");
    ShowExistWord(root, "app");

    root->insert("app");
    ShowExistWord(root, "app");
    root->remove("app");
    ShowExistWord(root, "app");
}
