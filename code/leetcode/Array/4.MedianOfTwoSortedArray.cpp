/*
* Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays. 
* The overall run time complexity should be O(log (m+n)).
*
* https://leetcode.com/problems/median-of-two-sorted-arrays/
*/

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if (m > n)
            return findMedianSortedArrays(nums2, nums1);
        
        int low = 0;
        int high = m;
        int total = m + n;

        while (low <= high) {
            int i = (low + high) / 2;
            int j = (total + 1) / 2 - i;

            int left1 = (i > 0)?nums1[i-1]:INT32_MIN;
            int right1 = (i < m)?nums1[i]:INT32_MAX;
            int left2 = (j > 0)?nums2[j-1]:INT32_MIN;
            int right2 = (j < n)?nums2[j]:INT32_MAX;

            // partition is correct
            if (left1 <= right2 && right1 >= left2) {
                // even
                if (total % 2 == 0) {
                    return  (max(left1, left2) + min(right1, right2)) / 2.0;
                } else {
                    return max(left1, left2);
                }
            } else if (left1 > right2) {
                high = i - 1;
            } else {
                low = i + 1;
            }
        }
        return 0;
    }
};

TEST(FindMedianSortedArrays, Examp1) {
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    Solution sol;

    ASSERT_EQ(sol.findMedianSortedArrays(nums1, nums2), 2.0);
}

TEST(FindMedianSortedArrays, Examp2) {
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    Solution sol;

    ASSERT_EQ(sol.findMedianSortedArrays(nums1, nums2), 2.5);
}
