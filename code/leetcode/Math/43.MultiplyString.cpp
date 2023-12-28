/*
* Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
*
* Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
*
* https://leetcode.com/problems/multiply-strings/description/
*/

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();

        string result(m + n, '0');

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int sum = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0');
                result[i + j + 1] = sum % 10 + '0';
                result[i + j] += sum / 10;
            }
        }

        for (int i = 0; i < m + n; i++) {
            if (result[i] != '0') { return result.substr(i); }
        }
        return "0";
    }
};

TEST(Multiply, Example1) {
    string num1 = "3";
    string num2 = "2";
    string ans = "6";

    Solution sol;

    ASSERT_EQ(sol.multiply(num1, num2), ans);
}

TEST(Multiply, Example2) {
    string num1 = "123";
    string num2 = "456";
    string ans = "56088";

    Solution sol;

    ASSERT_EQ(sol.multiply(num1, num2), ans);
}
