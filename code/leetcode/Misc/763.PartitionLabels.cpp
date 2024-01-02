/*
    Partition string so each letter appears in at most 1 part, return sizes
    Ex. s = "ababcbacadefegdehijhklij" -> [9,7,8]

    Greedy: determine last occurrence of each char, then loop thru & get sizes

    Time: O(n)
    Space: O(1)

    https://leetcode.com/problems/partition-labels/description/
*/

#include <gtest/gtest.h>

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        // {char -> last index in s}
        vector<int> lastIndex(26);
        for (int i = 0; i < n; i++) { lastIndex[s[i] - 'a'] = i; }

        int size = 0;
        int end = 0;

        vector<int> result;

        for (int i = 0; i < n; i++) {
            size++;
            // constantly checking for further indices if possible
            end = max(end, lastIndex[s[i] - 'a']);
            if (i == end) {
                result.push_back(size);
                size = 0;
            }
        }

        return result;
    }
};

TEST(PartitionLabels, Example1) {
    Solution sol;
    string s = "ababcbacadefegdehijhklij";
    vector<int> ans = {9, 7, 8};

    ASSERT_EQ(sol.partitionLabels(s), ans);
}

TEST(PartitionLabels, Example2) {
    Solution sol;
    string s = "eccbbbbdec";
    vector<int> ans = {10};

    ASSERT_EQ(sol.partitionLabels(s), ans);
}
