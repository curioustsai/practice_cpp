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
            for (size_t j = 0; j < L.size(); j++) {
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
        vector<int> result;

        sort(L.begin(), L.end());
        int length = L.size() - 1;

        if (L[0] + L[length] > target) return result;

        for (size_t i = 0; i < L.size(); i++) {
            int res = target - L[i];
            int j = binary_search(L, res);
            if (j != -1) {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }

        return result;
    }

    // version3: hash
    vector<int> twoSum3(vector<int> &L, int target) {
        vector<int> result;
        unordered_map<int, int> hash;

        for (size_t i = 0; i < L.size(); i++) {
            int temp = target - L[i];
            auto search = hash.find(temp);
            if (search != hash.end()) {
                result.push_back(i);
                result.push_back(search->second);
            }
            hash.insert(pair<int, int>(L[i], i));
        }

        if (result.size() == 0) {
            result.push_back(0);
            result.push_back(0);
        }

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

//int main (int argc, char *argv[])
int main() {
    Solution sol;
    // vector<int> L = {1,2,3,4,5};
    vector<int> L = {5, 2, 1, 4, 3};
    vector<int> res = sol.twoSum2(L, 6);

    for (int &i : res) { cout << i << endl; }

    return 0;
}
