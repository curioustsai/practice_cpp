/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, and /. Each operand may be an integer or another expression.
Note that division between two integers should truncate toward zero.
It is guaranteed that the given RPN expression is always valid.
That means the expression would always evaluate to a result, and there will not be any division by zero operation.

https://leetcode.com/problems/evaluate-reverse-polish-notation/
*/

#include <gtest/gtest.h>

#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans = 0;
        stack<int> st;
        for (auto& s : tokens) {
            if (s.size() > 1 || isdigit(s[0])) {
                st.push(stoi(s));
            } else {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                switch (s[0]) {
                    case '+':
                        num1 += num2;
                        break;
                    case '-':
                        num1 -= num2;
                        break;
                    case '*':
                        num1 *= num2;
                        break;
                    case '/':
                        num1 /= num2;
                        break;
                }
                st.push(num1);
            }
        }
        return st.top();
    }

    // fancy lambda
    int evalRPN_lambda(vector<string>& tokens) {
        unordered_map<string, function<int(int, int)>> map = {
            {"+", [](int a, int b) { return a + b; }},
            {"-", [](int a, int b) { return a - b; }},
            {"*", [](int a, int b) { return a * b; }},
            {"/", [](int a, int b) { return a / b; }}};
        std::stack<int> stack;
        for (string& s : tokens) {
            if (!map.count(s)) {
                stack.push(stoi(s));
            } else {
                int op1 = stack.top();
                stack.pop();
                int op2 = stack.top();
                stack.pop();
                stack.push(map[s](op2, op1));
            }
        }
        return stack.top();
    }
};

TEST(EvalRPN, Example1) {
    Solution sol;
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    int ans = 9;
    ASSERT_EQ(sol.evalRPN(tokens), ans);
}

TEST(EvalRPN, Example2) {
    Solution sol;
    vector<string> tokens = {"4", "13", "5", "/", "+"};
    int ans = 6;
    ASSERT_EQ(sol.evalRPN(tokens), ans);
}
