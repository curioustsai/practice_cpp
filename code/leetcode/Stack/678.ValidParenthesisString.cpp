/*
*   https://leetcode.com/problems/valid-parenthesis-string/description/
*/

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int balance = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '*')
                balance++;
            else
                balance--;

            if (balance < 0)
                return false;
        }

        if (balance == 0)
            return true;

        balance = 0;
        for (int i = s.size()-1; i >= 0; i--) {
            if (s[i] == ')' || s[i] == '*')
                balance++;
            else
                balance--;
            if (balance < 0)
                return false;
        }

        return true;
    }
};
