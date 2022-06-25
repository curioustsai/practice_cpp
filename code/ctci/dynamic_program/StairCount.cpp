#include <gtest/gtest.h>
#include <iostream>

using namespace std;

int StairCount(int n) {
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else {
        return StairCount(n - 1) + StairCount(n - 2);
    }
}

TEST(StairCount, Main) {
    cout << StairCount(4) << endl;
    ASSERT_EQ(StairCount(4), 5);
}
