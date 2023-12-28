/*
 * Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
 *
 *  https://leetcode.com/problems/powx-n/description/
*/

#include <gtest/gtest.h>
#include <math.h>

class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        double curr = x;

        for (int exp = abs(n); exp > 0; exp /= 2) {
            if (exp % 2 == 1) result *= curr;
            curr *= curr;
        }

        return (n < 0) ? 1.0 / result : result;
    }
};

TEST(MyPow, Example1) {
    double x = 2;
    int n = 10;
    double ans = 1024;
    Solution sol;

    ASSERT_EQ(sol.myPow(x, n), ans);
}

TEST(MyPow, Example2) {
    double x = 2.1;
    int n = 10;
    double ans = 1024;
    Solution sol;

    ASSERT_EQ(sol.myPow(x, n), ans);
}

TEST(MyPow, Example3) {
    double x = 2.0;
    int n = -2;
    double ans = 0.25;
    Solution sol;

    ASSERT_EQ(sol.myPow(x, n), ans);
}
