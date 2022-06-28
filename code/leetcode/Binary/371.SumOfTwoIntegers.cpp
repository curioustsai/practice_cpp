#include <gtest/gtest.h>

using namespace std;

//Given two integers a and b, return the sum of the two integers without using the operators + and -.

class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            unsigned int carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        return a;
    }
};

TEST(Binary, getSum) {
    Solution sol;
    int a = 1, b = 2;
    int ans = 3;
    ASSERT_EQ(sol.getSum(a, b), ans);
}

TEST(Binary, getSum2) {
    Solution sol;
    int a = 2, b = 3;
    int ans = 5;
    ASSERT_EQ(sol.getSum(a, b), ans);
}
