/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character.
You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.

Solution:
https://leetcode.com/problems/longest-repeating-character-replacement/discuss/91285/Sliding-window-similar-to-finding-longest-substring-with-k-distinct-characters
*/

#include <gtest/gtest.h>

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // sliding window, fix end point and slide the start point.
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int start = 0;
        int size = s.size();
        int res = 0;
        int maxCount = 0;

        for (int end = 0; end < size; end++) {
            int index_e = s[end] - 'A';
            count[index_e]++;
            if (count[index_e] > maxCount) { maxCount = count[index_e]; }

            // length of substring = end - start + 1
            // (length of substring - number of times of the maximum occurring character in the substring) <= k
            // sliding window, shrinking
            while (end - start - maxCount + 1 > k) {
                int index_s = s[start] - 'A';
                count[index_s]--;
                start++;
            }
            res = max(res, end - start + 1);
        }
        return res;
    }

    // T.C: O(n)
    // S.C: O(1)
    int characterReplacement_opt(string s, int k) {
        vector<int> count(26);
        int maxCount = 0;

        int i = 0;
        int j = 0;

        int result = 0;

        while (j < s.size()) {
            count[s[j] - 'A']++;
            maxCount = max(maxCount, count[s[j] - 'A']);
            if (j - i + 1 - maxCount > k) {
                count[s[i] - 'A']--;
                i++;
            }
            result = max(result, j - i + 1);
            j++;
        }

        return result;
    }
};

TEST(CharacterReplacement, Example1) {
    Solution sol;
    string s = "ABAB";
    int k = 2;
    int ans = 4;
    ASSERT_EQ(sol.characterReplacement(s, k), ans);
}

TEST(CharacterReplacement, Example2) {
    Solution sol;
    string s = "AABABBA";
    int k = 1;
    int ans = 4;
    ASSERT_EQ(sol.characterReplacement(s, k), ans);
}
