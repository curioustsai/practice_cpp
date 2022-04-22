#include <gtest/gtest.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
    public:
    /*
     * reveser the array in place
     * @param nums: an array
     * @return: None
     */
    void reverseArray(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }

    }

};

TEST(ReverseArray, TestVector)
{
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6};
    vector<int> ans = {6, 5, 4, 3, 2, 1, 0};
    Solution sol;
    sol.reverseArray(nums);

    // vector<int> res = sol.rotate(nums, 3);
    ASSERT_EQ(equal(nums.begin(), nums.end(), ans.begin()), true);
    sol.reverseArray(nums);
}
