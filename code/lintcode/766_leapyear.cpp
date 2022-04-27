// check if the given year is leap year

#include <iostream>
using namespace std;

class Solution {
public:
    bool isLeapYear(int year) {
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                if (year % 400 == 0) {
                    return true;
                } else {
                    return false;
                }
            }
            return true;
        }

        return false;
    }
};

int main() {
    Solution sol;

    cout << boolalpha << sol.isLeapYear(2000) << endl;
    cout << boolalpha << sol.isLeapYear(1900) << endl;
    cout << boolalpha << sol.isLeapYear(1800) << endl;
    cout << boolalpha << sol.isLeapYear(2004) << endl;
}
