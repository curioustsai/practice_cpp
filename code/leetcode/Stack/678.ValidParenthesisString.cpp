/*
 * Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
 * The following rules define a valid string:
 * 
 * Any left parenthesis '(' must have a corresponding right parenthesis ')'.
 * Any right parenthesis ')' must have a corresponding left parenthesis '('.
 * Left parenthesis '(' must go before the corresponding right parenthesis ')'.
 * '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 *
 *  https://leetcode.com/problems/valid-parenthesis-string/description/
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

            if (balance < 0) return false;
        }

        if (balance == 0) return true;

        balance = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ')' || s[i] == '*')
                balance++;
            else
                balance--;
            if (balance < 0) return false;
        }

        return true;
    }
};
