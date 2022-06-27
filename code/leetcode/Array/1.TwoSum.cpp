#include <gtest/gtest.h>

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param L: Given a group of numbers
     * @param target: target sum
     * @return: index of num that meet the target
     */

    // brute force
    vector<int> twoSum(vector<int> &L, int target) {
        vector<int> result(2, 0);

        for (size_t i = 0; i < L.size(); i++) {
            for (size_t j = i + 1; j < L.size(); j++) {
                if (L[i] + L[j] == target) {
                    result[0] = i;
                    result[1] = j;
                    return result;
                }
            }
        }

        return result;
    }

    // complexity: O(nlogn)
    vector<int> twoSum2(vector<int> &L, int target) {
        vector<int> result(2, 0);

        sort(L.begin(), L.end());
        int length = L.size() - 1;

        if (L[0] + L[length] > target) return result;

        for (size_t i = 0; i < L.size(); i++) {
            int res = target - L[i];
            int j = binary_search(L, res);
            if (j != -1) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }

        return result;
    }

    // version3: hash
    vector<int> twoSum3(vector<int> &L, int target) {
        vector<int> result(2, 0);
        unordered_map<int, int> hash;

        for (size_t i = 0; i < L.size(); i++) {
            int temp = target - L[i];
            auto search = hash.find(temp);
            if (search != hash.end()) {
                result[0] = i;
                result[1] = search->second;
            }
            hash.insert(pair<int, int>(L[i], i));
        }

        if (result.size() == 0) {
            result[0] = 0;
            result[1] = 0;
        }
        sort(result.begin(), result.end());
        return result;
    }

private:
    int binary_search(vector<int> &arr, int target) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
};

TEST(TwoSum, Test1) {
    Solution sol;
    vector<int> L = {2, 7, 11, 15};
    int target = 9;
    vector<int> res = sol.twoSum3(L, target);
    vector<int> ans = {0, 1};

    for (int i = 0; i < ans.size(); i++) { ASSERT_EQ(ans[i], res[i]); }
}

TEST(TwoSum, Test2) {
    Solution sol;
    vector<int> L = {3, 2, 4};
    int target = 6;
    vector<int> res = sol.twoSum3(L, target);
    vector<int> ans = {1, 2};

    for (int i = 0; i < ans.size(); i++) { ASSERT_EQ(ans[i], res[i]); }
}

TEST(TwoSum, Test3) {
    Solution sol;
    vector<int> L = {3, 3};
    int target = 6;
    vector<int> res = sol.twoSum3(L, target);
    vector<int> ans = {0, 1};

    for (int i = 0; i < ans.size(); i++) { ASSERT_EQ(ans[i], res[i]); }
}
