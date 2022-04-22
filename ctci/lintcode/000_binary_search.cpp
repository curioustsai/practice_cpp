#include <gtest/gtest.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class BinarySearch {
public:
    /*
    * @param data: an array
    * @return: index if success, -1 failed.
    */
    int search(vector<int> arr, int target) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == target)
                return mid;
            else if (arr[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }

    int search_v2(vector<int> arr, int target, int left, int right) {
        if (left > right) return -1;

        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] > target) {
            right = mid - 1;
            return search_v2(arr, target, left, right);
        } else {
            left = mid + 1;
            return search_v2(arr, target, left, right);
        }
    }
};

TEST(BinarySearch, search)
{
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6};
    BinarySearch bs;
    ASSERT_EQ(bs.search(arr, 4), 4);
}

