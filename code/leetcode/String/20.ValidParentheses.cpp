/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
*/

#include <gtest/gtest.h>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) return false;

                if ((st.top() == '(' && c != ')') || (st.top() == '{' && c != '}') ||
                    (st.top() == '[' && c != ']')) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
    // wrong, didn't think about order
    // bool isValid(string s) {
    //     int count1 = 0; // ()
    //     int count2 = 0; // {}
    //     int count3 = 0; // []

    //     for (char c : s) {
    //         if (c == '(') {
    //             count1++;
    //         } else if (c == ')') {
    //             count1--;
    //         }
    //         if (c == '{') {
    //             count2++;
    //         } else if (c == '}') {
    //             count2--;
    //         }
    //         if (c == '[') {
    //             count3++;
    //         } else if (c == ']') {
    //             count3--;
    //         }
    //     }
    //     if (count1 == 0 && count2 == 0 && count3 == 0) return true;
    //     return false;
    // }
};

TEST(VadliParantheses, Example1) {
    Solution sol;
    string input = "()";
    bool output = true;

    ASSERT_EQ(sol.isValid(input), output);
}

TEST(VadliParantheses, Example2) {
    Solution sol;
    string input = "()[]{}";
    bool output = true;

    ASSERT_EQ(sol.isValid(input), output);
}

TEST(VadliParantheses, Example3) {
    Solution sol;
    string input = "(]";
    bool output = false;

    ASSERT_EQ(sol.isValid(input), output);
}
