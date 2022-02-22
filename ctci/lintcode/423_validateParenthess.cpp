#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
    public:
    /*
     * @param s: a string
     * @return: where the string is a valid parentheses
     */
    bool validateParethenses(string &s)
    {
        stack<char> pstack;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                pstack.push(s[i]);

            if (s[i] == ')') {
                if (pstack.top() == '(') {
                    pstack.pop();
                } else {
                    return false;
                }
            } else if (s[i] == ']') {
                if (pstack.top() == '[') {
                    pstack.pop();
                } else {
                    return false;
                }
            } else if (s[i] == '}') {
                if (pstack.top() == '{') {
                    pstack.pop();
                } else {
                    return false;
                }
            }
        }

        if (!pstack.empty())
            return false;
        return true;
    }
};

int main (int argc, char *argv[])
{
    string str1 = "([)]"; //false
    string str2 = "()[]{}"; //true

    Solution sol;
    cout << boolalpha << sol.validateParethenses(str1) << endl;
    cout << boolalpha << sol.validateParethenses(str2) << endl;

    return 0;
}
