#include <iostream>

using namespace std;

bool isOneEdit(string str1, string str2) {
    string strLong, strShort;
    int lenLong, lenShort;

    strLong = (str2.size() < str1.size()) ? str1 : str2;
    strShort = (str2.size() < str1.size()) ? str2 : str1;
    lenLong = strLong.size();
    lenShort = strShort.size();

    if ((lenLong - lenShort) > 1) return false;

    // one edit
    // case 1: miss one letter
    // case 2: insert one letter
    // case 3: replace one letter

    int i = 0, j = 0;
    bool mismatchDone = false;
    while (i < lenShort && j < lenLong) {
        if (strShort[i] != strLong[j]) {
            if (mismatchDone) {
                return false;
            }
            mismatchDone = true;
            if (lenLong == lenShort) {
                ++i;  // case 3: replace
            }
        } else {
            ++i;  // move short pointer if its a match, dont move it in case of
                  // first mismatch
        }
        ++j;  // always move long string pointer.
    }

    return true;
}

int main() {
    string str1, str2;
    cout << "enter string1" << endl;
    getline(cin, str1);
    cout << "enter string2" << endl;
    getline(cin, str2);

    cout << boolalpha << isOneEdit(str1, str2) << endl;

    return 0;
}
