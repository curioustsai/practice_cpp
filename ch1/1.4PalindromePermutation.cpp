
#include <iostream>

using namespace std;

constexpr int NUM_LETTERS = 26;

int getValue(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch - 'a';
    } else if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A';
    }

    return -1;
}

bool isPalidromePermutation(string str) {
    int hit[NUM_LETTERS] = {0};

    for (int i = 0; i < str.size(); i++) {
        int val = getValue(str[i]);
        if (val >= 0) {
            hit[val]++;
        }
    }

    int sum = 0;
    bool bSingleOdd = false;
    for (int i = 0; i < NUM_LETTERS; i++) {
        if (hit[i] % 2) {
            if (bSingleOdd) {
                return false;
            }
            bSingleOdd = true;
        }
        sum += hit[i];
    }

    if (sum == 0) return false;

    return true;
}

int main() {
    string str;
    cout << "enter string" << endl;
    getline(cin, str);
    cout << boolalpha << isPalidromePermutation(str) << endl;

    return 0;
}
