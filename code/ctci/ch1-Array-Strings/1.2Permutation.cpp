// Given 2 strings, write a method to decide if one is a permuatation of the
// other

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool isPermutation2(string str1, string str2) {
    if (str1.size() != str2.size()) return false;

    int count[256] = {0};

    for (int i = 0; i < str1.size(); i++) {
        int val = str1[i];
        count[val]++;
    }

    for (int i = 0; i < str2.size(); i++) {
        int val = str2[i];
        count[val]--;
    }

    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) return false;
    }

    return true;
}

bool isPermutation(string str1, string str2) {
    if (str1.size() != str2.size()) return false;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    if (str1.compare(str2) != 0) return false;

    return true;
}

int main() {
    string str1, str2;

    cout << "Enter str1" << endl;
    getline(cin, str1);
    cout << "Enter str2" << endl;
    getline(cin, str2);

    //method 1
    cout << str1 << " is permuatation of " << str2 << " " << boolalpha << isPermutation(str1, str2)
         << endl;

    //method 2
    cout << str1 << " is permuatation of " << str2 << " " << boolalpha << isPermutation2(str1, str2)
         << endl;

    return 0;
}
