/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

https://leetcode.com/problems/word-break
*/

#include <gtest/gtest.h>

#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    /*
    Time complexity O(2^n), explaintion
    https://leetcode.com/problems/word-break/discuss/169383/solved-The-Time-Complexity-of-The-Brute-Force-Method-Should-Be-O(2n)-and-Prove-It-Below
    */
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> wordSet(wordDict.begin(), wordDict.end());
        return check(s, wordSet);
    }

    bool check(string s, set<string>& wordSet) {
        int length = s.length();
        if (length == 0) return true;

        for (int i = 1; i <= length; i++) {
            if (wordSet.count(s.substr(0, i)) && check(s.substr(i), wordSet)) { return true; }
        }
        return false;
    }

    // memorize, skip too long execution
    bool wordBreak2(string s, vector<string>& wordDict) {
        set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(), -1);
        return check2(s, wordSet, 0, memo);
    }

    bool check2(string s, set<string>& wordSet, int start, vector<int>& memo) {
        if (start > s.size()) return true;
        if (memo[start] != -1) return memo[start];
        for (int i = start + 1; i < s.size(); ++i) {
            if (wordSet.count(s.substr(start, i - start)) && check2(s, wordSet, i, memo)) {
                memo[start] = 1;
                return memo[start];
            }
        }
        memo[start] = 0;
        return memo[start];
    }

    // dp version
    bool wordBreak_dp(string s, vector<string>& wordDict) {
        set<string> words;
        for (int i = 0; i < wordDict.size(); i++) { words.insert(wordDict[i]); }

        int n = s.size();
        vector<bool> dp(n + 1);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j]) {
                    string word = s.substr(j, i - j);
                    if (words.find(word) != words.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[n];
    }
};

TEST(WordBreak, ExampleI) {
    Solution sol;
    string input = "leetcode";
    vector<string> wordDict = {"leet", "code"};

    ASSERT_EQ(sol.wordBreak(input, wordDict), true);
}

TEST(WordBreak, ExampleII) {
    Solution sol;
    string input = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};

    ASSERT_EQ(sol.wordBreak(input, wordDict), true);
}

TEST(WordBreak, ExampleIII) {
    Solution sol;
    string input = "catsandodg";
    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};

    ASSERT_EQ(sol.wordBreak(input, wordDict), false);
}

TEST(WordBreak, ExampleIV) {
    Solution sol;
    string input = "a";
    vector<string> wordDict = {"a"};

    ASSERT_EQ(sol.wordBreak(input, wordDict), true);
}
