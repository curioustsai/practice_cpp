/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time

https://leetcode.com/problems/longest-consecutive-sequence/
*/
#include <gtest/gtest.h>

#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    // Time Complexity O(n), use set
    int longestConsecutiveSequence(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> record(nums.begin(), nums.end());
        int res = 1;
        for (auto n : nums) {
            if (record.find(n) == record.end()) continue;
            record.erase(n);

            int prev = n - 1, next = n + 1;
            while (record.find(prev) != record.end()) record.erase(prev--);
            while (record.find(next) != record.end()) record.erase(next++);
            res = max(res, next - 1 - prev - 1 + 1);
        }

        return res;
    }
};

TEST(LongestConsecutiveSequence, Example1) {
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int ans = 4;

    ASSERT_EQ(sol.longestConsecutiveSequence(nums), ans);
}

TEST(LongestConsecutiveSequence, Example2) {
    Solution sol;
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    int ans = 9;

    ASSERT_EQ(sol.longestConsecutiveSequence(nums), ans);
}
