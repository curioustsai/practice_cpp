#include <gtest/gtest.h>

// TODO: explain
// another method: diff
void swap(int& x, int& y) {
    // bitwise xor
    // 0, 0, 0
    // 1, 0, 1
    // 0, 1, 1
    // 1, 1, 0
    x = x ^ y; // save difference btw x and y
    y = x ^ y; // y = orignal x
    x = x ^ y; // x = orignal y
}

TEST(Medium, swap) {
    int a = 1234;
    int b = 5678;
    swap(a, b);

    ASSERT_EQ(a, 5678);
    ASSERT_EQ(b, 1234);
}
