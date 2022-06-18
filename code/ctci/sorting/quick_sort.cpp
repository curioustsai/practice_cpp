#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

void partition(vector<int>& arr, int begin, int end) {
    // choose the midpoint as pivot
    int mid = (begin + end) / 2;
    int pivot = arr[mid];
    int left = begin;
    int right = end - 1;

    swap(arr[mid], arr[end]);

    while (left < right) {
        while (arr[left] < pivot) { left++; }
        while (arr[right] > pivot) { right--; }
        swap(arr[left], arr[right]);
    }

    if (arr[mid] > arr[end]) swap(arr[mid], arr[end]);
}

void quick_sort(vector<int>& arr, int begin, int end) {
    //divided and conquer
    if (begin >= end) return;

    partition(arr, begin, end);
    int mid = (begin + end) / 2;
    quick_sort(arr, begin, mid);
    quick_sort(arr, mid + 1, end);
}

TEST(Sort, Quick) {
    vector<int> arr = {0, 5, 4, 1, 3, 8, 2, 7, 9, 6};
    for (auto a : arr) { cout << a << " "; }
    cout << endl;
    // sort(arr.begin(), arr.end());

    quick_sort(arr, 0, arr.size() - 1);

    for (auto a : arr) { cout << a << " "; }
    cout << endl;
}
