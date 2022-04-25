/*
 * String compression
 * input: aabbcc
 * output: a2b2c2
 *
 * note: std::to_string(int )
 */

#include <iostream>

using namespace std;

bool compressString(string& str) {
    string out{""};
    int count = 1;
    int j = 1;

    // last index is null-terminated
    while (j < str.size()) {
        if (str[j] == str[j - 1]) {
            count++;
        } else {
            out += str[j - 1];
            out += std::to_string(count);
            count = 1;
        }
        j++;
    }

    if (out.size() > str.size()) return false;
    str = out;

    return true;
}

int main() {
    string original;
    // cout << "enter string" << endl;
    // getline(cin, original);
    original = "aabbccdd";
    compressString(original);
    cout << "compress:" << original << endl;

    return 0;
}
