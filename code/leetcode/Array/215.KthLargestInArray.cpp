#include <gtest/gtest.h>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // O(n)
    int findKthLargest(vector<int>& nums, int k) {
        int low = 0;
        int high = nums.size() - 1;
        int pivotIndex = nums.size();

        while (pivotIndex != k-1) {
            pivotIndex = partition(nums, low, high);

            if (pivotIndex < k-1) {
                low = pivotIndex + 1;
            } else {
                high = pivotIndex - 1;
            }
        }

        return nums[k-1];
    }

private:
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low];
        int i = low + 1;
        int j = high;
        
        while (i <= j) {
            if (nums[i] < pivot && pivot < nums[j]) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }

            if (nums[i] >= pivot) i++;
            if (nums[j] <= pivot) j--;
        }
        swap(nums[low], nums[j]);
        return j;
    }

};

class Solution2 {
public:
    // O(n logk)
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num : nums) {
            pq.push(num);

            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};


TEST(KthLargest, Sol1_1) {
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    int ans = 5;

    Solution sol;

    ASSERT_EQ(sol.findKthLargest(nums, k), ans);

}

TEST(KthLargest, Sol1_2) {
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    int ans = 4;

    Solution sol;

    ASSERT_EQ(sol.findKthLargest(nums, k), ans);
}

TEST(KthLargest, Sol2_1) {
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    int ans = 5;

    Solution2 sol;

    ASSERT_EQ(sol.findKthLargest(nums, k), ans);

}

TEST(KthLargest, Sol2_2) {
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    int ans = 4;

    Solution2 sol;

    ASSERT_EQ(sol.findKthLargest(nums, k), ans);

}
