#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    /*
    * @param arr: pages of a group of books
    * @param n: the number of peopel work on
    * @return: time took for copy entire books
    */
    int copybook(vector<int> arr, int n) {
        // Two possilble solutions: binary search or dynamic programming
        // Implement binary serach version here
        size_t length = arr.size();
        int total_pages = 0;
        int max_pages = 0;

        for (size_t i = 0; i < length; ++i) {
            total_pages += arr[i];
            max_pages = max(arr[i], max_pages);
        }

        int start = max_pages;
        int end = total_pages;

        while (start + 1 < end) {
            int mid = start + (end - start) / 2;

            if (countCopier(arr, mid) > n) {
                // means everyone should share more pages
                start = mid;
            } else {
                end = mid;
            }
        }

        if (countCopier(arr, start) <= n)
            return start;

        return end;
    }

private:
    int countCopier(vector<int> arr, int limit) {
        int copier = 1;
        int pages = arr[0];

        for (size_t i = 1; i < arr.size(); i++) {
            if (arr[i] + pages > limit) {
                copier++;
                pages = 0;
            }
            pages += arr[i];
        }

        return copier;
    }
};

int main(int argc, char *argv[]) {
    vector<int> pages1 = {3, 2, 4};
    int k1 = 2;

    vector<int> pages2 = {3, 2, 4};
    int k2 = 3;

    Solution sol;

    cout << sol.copybook(pages1, k1) << endl; // 5
    cout << sol.copybook(pages2, k2) << endl; // 4

    return 0;
}
