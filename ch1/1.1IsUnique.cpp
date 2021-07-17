#include <bitset>
#include <iostream>
#include <string>

using namespace std;

bool isUnique_bitset(string str) {
    bitset<256> bitmap(0);
    for (int i = 0; i < str.size(); i++) {
        int val = str[i];
        if (bitmap.test(val) > 0) {
            return false;
        }
        bitmap.set(val);
    }
    return true;
}

bool isUnique(string str) {
    for (int i = 0; i < str.size(); i++) {
        for (int j = i + 1; j < str.size(); j++) {
            if (str[i] == str[j]) return false;
        }
    }
    return true;
}

int main() {
    string str = "abc";
    cout << str << " is unique: " << boolalpha << isUnique(str) << endl;

    return 0;
}
