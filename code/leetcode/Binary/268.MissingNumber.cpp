#include <gtest/gtest.h>

using namespace std;

/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
*/

class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(n)
    int missingNumber(vector<int>& nums) {
        vector<bool> exist(nums.size() + 1, false);
        for (int n : nums) { exist[n] = true; }
        for (int i = 0; i <= nums.size(); i++) {
            if (!exist[i]) return i;
        }

        return -1;
    }

    // Time complexity: O(n)
    // Space complexity: O(1)
    int missingNumber_opt(vector<int>& nums) {
        int n = nums.size();
        int sum_all = n * (n + 1) / 2;
        int sum = 0;
        for (int i = 0; i < n; i++) { sum += nums[i]; }

        return (sum_all - sum);
    }
};

TEST(Binary, MissingNumber) {
    Solution sol;
    vector<int> input = {3, 0, 1};
    int ans = 2;
    ASSERT_EQ(sol.missingNumber_opt(input), ans);
}

TEST(Binary, MissingNumberII) {
    Solution sol;
    vector<int> input = {0, 1};
    int ans = 2;
    ASSERT_EQ(sol.missingNumber_opt(input), ans);
}

TEST(Binary, MissingNumberIII) {
    Solution sol;
    vector<int> input = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int ans = 8;
    ASSERT_EQ(sol.missingNumber_opt(input), ans);
}
