/*
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses. 
 * Ex. n = 3 -> ["((()))","(()())","(())()","()(())","()()()"], n = 1 -> ["()"]
 * https://leetcode.com/problems/generate-parentheses/
*/

#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        helper(n, 0, 0, "", result);
        return result;
    }
    // backtracking
    void helper(int n, int open, int close, string curr, vector<string>& result) {
        if (open == n && close == n) {
            result.push_back(curr);
            return;
        }

        if (open < n) helper(n, open + 1, close, curr + '(', result);
        if (open > close) helper(n, open, close + 1, curr + ')', result);
    }
};

TEST(generateParenthesis, Example1) {
    int n = 3;
    Solution sol;
    vector<string> ans = {"((()))","(()())","(())()","()(())","()()()"};
    ASSERT_EQ(sol.generateParenthesis(n), ans);
}

TEST(generateParenthesis, Example2) {
    int n = 1;
    Solution sol;
    vector<string> ans = {"()"};
    ASSERT_EQ(sol.generateParenthesis(n), ans);
}
