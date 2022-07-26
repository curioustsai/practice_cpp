/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

https://leetcode.com/problems/word-ladder/
*/

#include <gtest/gtest.h>

#include <queue>
#include <stack>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ladder = 1;
        unordered_set<string> myset(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);

        while (!q.empty()) {
            int n = q.size();
            for (int k = 0; k < n; k++) {
                string word = q.front();
                q.pop();
                if (word == endWord) return ladder;
                myset.erase(word);

                for (int i = 0; i < word.size(); i++) {
                    char c = word[i];
                    for (int j = 0; j < 26; j++) {
                        word[i] = 'a' + j;

                        if (myset.count(word)) { q.push(word); }
                    }
                    word[i] = c;
                }
            }
            ladder++;
        }

        return 0;
    }
};

TEST(LadderLength, Example1) {
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    int output = 5;

    ASSERT_EQ(sol.ladderLength(beginWord, endWord, wordList), output);
}

TEST(LadderLength, Example2) {
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log"};
    int output = 0;

    ASSERT_EQ(sol.ladderLength(beginWord, endWord, wordList), output);
}
