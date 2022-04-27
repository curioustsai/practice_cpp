/**
 * Cracking the coding interview 1-9
 * You have a function "isSubstring" which checks whether a string is substring
 * of another. Given two strings s1 and s2, write code to check if s2 is a
 * rotation of s1 using only one call to "isSubstring".
 *
 * Approach:
 * example s1 = "waterbottle", and s2 = "erbottlewat", clearly s2 is rotation of
 * s1. lets say s1 = xy ==> wat + erbottle similarly s2 = yx ==> erbottle + wat
 * Therefore s1s1 = "waterbottlewaterbottle", clearly s2 is substring of s1s1
 * So if a string is formed by rotation of another string, it will always be
 * substring of concatenated original string to itself.
 */

#include <iostream>
#include <string>

using namespace std;

bool isStringRotate(string& str1, string& str2) {
    if (str1.size() == 0 || str1.size() != str2.size()) return false;

    string concat = str1 + str1;
    if (concat.find(str2) != string::npos) { return true; }
    return false;
}

int main() {
    string str1, str2;
    str1 = "waterbottle";
    str2 = "erbottlewat";
    cout << boolalpha << isStringRotate(str1, str2) << endl;

    return 0;
}
