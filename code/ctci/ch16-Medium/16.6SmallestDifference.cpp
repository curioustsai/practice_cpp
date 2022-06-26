#include <algorithm>
#include <gtest/gtest.h>

using namespace std;
int SmallestDifference(vector<int> v1, vector<int> v2) {
    int smallest_diff = INT32_MAX;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int a = 0, b = 0;

    while (a < v1.size() && b < v2.size()) {
        int temp = abs(v1[a] - v2[b]);
        if (temp < smallest_diff) { smallest_diff = temp; }

        if (v1[a] < v2[b]) {
            a++;
        } else {
            b++;
        }
    }

    return smallest_diff;
}

TEST(Medium, SmallestDifference) {
    vector<int> v1 = {1, 3, 15, 11, 2}, v2 = {23, 127, 235, 19, 8};
    ASSERT_EQ(3, SmallestDifference(v1, v2));
}
