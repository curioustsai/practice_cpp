/*
Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

https://leetcode.com/problems/basic-calculator/
*/

#include <gtest/gtest.h>

#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> nums, ops;
        int res = 0, num = 0, sign = 1;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            } else {
                res += sign * num;
                num = 0;
                if (s[i] == '+') {
                    sign = 1;
                } else if (s[i] == '-') {
                    sign = -1;
                } else if (s[i] == '(') {
                    nums.push(res);
                    ops.push(sign);
                    res = 0;
                    sign = 1;
                } else if (s[i] == ')') {
                    res = res * ops.top() + nums.top();
                    ops.pop();
                    nums.pop();
                }
            }
        }
        res += sign * num;
        return res;
    }
};

TEST(BasicCalculator, Example1) {
    Solution sol;
    string input = "1 + 1";
    int output = 2;
    ASSERT_EQ(sol.calculate(input), output);
}

TEST(BasicCalculator, Example2) {
    Solution sol;
    string input = " 2-1 + 2";
    int output = 3;
    ASSERT_EQ(sol.calculate(input), output);
}

TEST(BasicCalculator, Example3) {
    Solution sol;
    string input = "(1+(4+5+2)-3+(6+8))";
    int output = 23;
    ASSERT_EQ(sol.calculate(input), output);
}
