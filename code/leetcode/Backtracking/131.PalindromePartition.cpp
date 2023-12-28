/*
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 * Return all possible palindrome partitioning of s.
 * https://leetcode.com/problems/palindrome-partitioning/
*/

#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        vector<vector<string>> results;

        dfs(s, 0, curr, results);
        return results;
    }

    void dfs(string s, int start, vector<string>& curr, vector<vector<string>>& results) {
        if (start == s.size()) {
            results.push_back(curr);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                string ss = s.substr(start, i - start + 1);
                curr.push_back(ss);
                dfs(s, i + 1, curr, results);
                curr.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            right--;
            left++;
        }
        return true;
    }
};

TEST(PalindromePartition, Example1) {
    Solution sol;
    string s = "aab";
    vector<vector<string>> ans = {{"a", "a", "b"}, {"aa", "b"}};

    ASSERT_EQ(sol.partition(s), ans);
}

TEST(PalindromePartition, Example2) {
    Solution sol;
    string s = "a";
    vector<vector<string>> ans = {{"a"}};

    ASSERT_EQ(sol.partition(s), ans);
}
