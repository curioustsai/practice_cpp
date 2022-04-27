#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     * @param nums: an array
     * @param k: an integer
     * @return: rotate the array to the right by k steps
     */
    vector<int> rotate_brute(vector<int> &nums, int k) {
        vector<int> result(nums.size(), 0);

        int length = nums.size();
        int i = 0;
        int j = length - k;
        while (j <= length - 1) {
            result[i] = nums[j];
            i++;
            j++;
        }

        j = 0;
        while (i <= length - 1) {
            result[i] = nums[j];
            i++;
            j++;
        }

        return result;
    }

    // complex O(n)
    // space O(1)
    vector<int> rotate(vector<int> &nums, int k) {
        if (k == 0 || nums.size() < 2) return nums;

        k = k % nums.size();
        reverse(nums.begin(), nums.begin() + nums.size() - k);
        reverse(nums.begin() + nums.size() - k, nums.end());
        reverse(nums.begin(), nums.end());

        return nums;
    }
};

TEST(Rotate, brute) {
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6};
    vector<int> ans = {4, 5, 6, 0, 1, 2, 3};
    Solution sol;

    // vector<int> res = sol.rotate(nums, 3);
    vector<int> res = sol.rotate_brute(nums, 3);
    ASSERT_EQ(equal(res.begin(), res.end(), ans.begin()), true);
}
