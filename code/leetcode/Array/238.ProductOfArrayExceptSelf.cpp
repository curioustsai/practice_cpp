#include <gtest/gtest.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     vector<int> res;
    //     //require O(n) and without using division operation
    //     for (int i = 0; i < nums.size(); i++) {
    //         int product = 1;
    //         for (int j = 0; j < i; j++) { product *= nums[j]; }
    //         for (int j = i + 1; j < nums.size(); j++) { product *= nums[j]; }
    //         res.push_back(product);
    //     }
    //     return res;
    // }

    //Time complexity:  O(n)
    //Space complexity: O(n), if answer array is ignored -> O(1)
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        int n = nums.size() - 1, left = 1, right = 1;

        for (int i = 0; i <= n; i++) {
            res[i] *= left;
            res[n - i] *= right;
            left *= nums[i];
            right *= nums[n - i];
        }
        return res;
    }
};

TEST(ContainsDuplicate, Test1) {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = {24, 12, 8, 6};

    ASSERT_EQ(equal(ans.begin(), ans.end(), sol.productExceptSelf(nums).begin()), true);
}

TEST(ContainsDuplicate, Test2) {
    Solution sol;
    vector<int> nums = {-1, 1, 0, -3, 3};
    vector<int> ans = {0, 0, 9, 0, 0};

    ASSERT_EQ(equal(ans.begin(), ans.end(), sol.productExceptSelf(nums).begin()), true);
}
