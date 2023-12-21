#include <gtest/gtest.h>
#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

int partition(vector<int>& arr, int begin, int end) {
    int left = begin;
    int right = end;
    int pivot = arr[begin];

    while (left < right) {
        while (arr[left] < pivot && left < right) { left++; }
        while (arr[right] > pivot && left < right) { right--; }
        swap(arr[left], arr[right]);
    }

    if (arr[begin] > arr[right]) { swap(arr[begin], arr[right]); }

    return right;
}

void quick_sort(vector<int>& arr, int low, int high) {
    //divided and conquer
    if (low >= high) return;

    int pivot = partition(arr, low, high);
    quick_sort(arr, low, pivot - 1);
    quick_sort(arr, pivot + 1, high);
}

TEST(Sorting, QuickSort) {
    vector<int> arr = {0, 5, 4, 1, 3, 8, 2, 7, 9, 6};
    vector<int> ans(arr.begin(), arr.end());

    // ascending
    sort(ans.begin(), ans.end());
    quick_sort(arr, 0, arr.size() - 1);

    ASSERT_EQ(arr, ans);
}
