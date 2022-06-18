#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int begin, int mid, int end) {
    //input: arr 1: [being, mid], arr 2: [mid+1, end]
    //output sorted [begin, end]

    int index1 = begin;
    int index2 = mid + 1;
    int index3 = 0;
    vector<int> sorted;
    sorted.resize(end - begin + 1);

    while (index1 <= mid && index2 <= end) {
        if (arr[index1] < arr[index2]) {
            sorted[index3] = arr[index1];
            index1++;
        } else {
            sorted[index3] = arr[index2];
            index2++;
        }
        index3++;
    }

    while (index1 <= mid) {
        sorted[index3] = arr[index1];
        index1++;
        index3++;
    }

    while (index2 <= end) {
        sorted[index3] = arr[index2];
        index2++;
        index3++;
    }

    for (int i = begin, j = 0; i <= end; i++, j++) { arr[i] = sorted[j]; }
}

void merge_sort(vector<int>& arr, int begin, int end) {
    if (begin >= end) return;

    // divide and conquer
    int mid = (begin + end) / 2;
    merge_sort(arr, begin, mid);
    merge_sort(arr, mid + 1, end);

    merge(arr, begin, mid, end);
}

TEST(Sort, Merge) {
    vector<int> arr = {0, 5, 4, 1, 3, 8, 2, 7, 9, 6};
    for (auto a : arr) { cout << a << " "; }
    cout << endl;
    // sort(arr.begin(), arr.end());

    merge_sort(arr, 0, arr.size() - 1);

    for (auto a : arr) { cout << a << " "; }
    cout << endl;
}
