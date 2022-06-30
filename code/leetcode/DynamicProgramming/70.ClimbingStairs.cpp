/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        } else {
            return climbStairs(n - 1) + climbStairs(n - 2);
        }
    }

    int climbStairs_opt(int n) {
        if (n <= 2) { return n; }

        vector<int> steps(n + 1, 0);
        steps[1] = 1;
        steps[2] = 2;

        for (int i = 3; i <= n; i++) { steps[i] = steps[i - 1] + steps[i - 2]; }

        return steps[n];
    }
};

TEST(ClimbStairs, ExampleI) {
    Solution sol;
    uint32_t input = 2;
    uint32_t ans = 2;
    ASSERT_EQ(sol.climbStairs_opt(input), ans);
}

TEST(ClimbStairs, ExampleII) {
    Solution sol;
    uint32_t input = 3;
    uint32_t ans = 3;
    ASSERT_EQ(sol.climbStairs_opt(input), ans);
}
