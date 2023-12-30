/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
*/

#include <gtest/gtest.h>
#include <stack>
#include <unordered_map>

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

    bool isValid2(string s) {
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

    bool isValid3(string s) {
        stack<char> open;
        unordered_map<char, char> parens = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };
        
        for (const auto& c : s) {
            if (parens.find(c) != parens.end()) {
                // if input starts with a closing bracket.
                if (open.empty()) {
                    return false;
                }

                if (open.top() != parens[c]) {
                    return false;
                }

                open.pop();
            } else {
                open.push(c);
            }
        }
        
        return open.empty();
    }
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
