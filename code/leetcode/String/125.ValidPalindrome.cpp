/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward.
Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.
*/

#include <gtest/gtest.h>
#include <stack>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                t += c;
            } else if (c >= 'A' && c <= 'Z') {
                char n = c + 'a' - 'A';
                t += n;
            } else if (c >= '0' && c <= '9') {
                t += c;
            }
        }

        int start = 0;
        int end = t.length() - 1;
        while (start < end) {
            if (t[start] != t[end]) return false;
            start++;
            end--;
        }

        return true;
    }
};

TEST(VadlidPalindrome, Example1) {
    Solution sol;
    string input = "A man, a plan, a canal: Panama";
    bool output = true;

    ASSERT_EQ(sol.isPalindrome(input), output);
}

TEST(VadlidPalindrome, Example2) {
    Solution sol;
    string input = "race a car";
    bool output = false;

    ASSERT_EQ(sol.isPalindrome(input), output);
}

TEST(VadlidPalindrome, Example3) {
    Solution sol;
    string input = " ";
    bool output = true;

    ASSERT_EQ(sol.isPalindrome(input), output);
}
TEST(VadlidPalindrome, Example4) {
    Solution sol;
    string input = "0P";
    bool output = false;

    ASSERT_EQ(sol.isPalindrome(input), output);
}
