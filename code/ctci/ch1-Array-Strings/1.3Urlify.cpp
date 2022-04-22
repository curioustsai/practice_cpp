/*
 * Urlify input string:
 * Replace space ' ' with '%20'
 */
#include <cstring>
#include <iostream>

using namespace std;

// void Urlify(char* str, int length) {
//     int capacity = strlen(str);
//
//     // find all ' '
//     int count = 0;
//     for (int i = 0; i < length; i++) {
//         if (str[i] == ' ') count++;
//     }
//     int length_all = length + 2 * count;
//
//     int index_new = length_all - 1;
//     int index_old = length - 1;
//     while (index_old >= 0) {
//         if (str[index_old] != ' ') {
//             str[index_new--] = str[index_old--];
//         } else {
//             str[index_new--] = '0';
//             str[index_new--] = '2';
//             str[index_new--] = '%';
//             index_old--;
//         }
//     }
// }
//
// int main() {
//     char str[] = "Mr John Smith      ";
//     Urlify(str, 13);
//     cout << str << endl;
//
//     return 0;
// }

string Urlify(string input) {
    string output;

    int space_count = 0;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == ' ') space_count++;
    }
    int outputSize = input.size() + space_count * (3 - 1);
    output.resize(outputSize);

    for (int i = 0, j = 0 ; i < input.size(); ++i, ++j) {
        if (input[i] != ' ') {
            output[j] = input[i];
        } else {
            output[j++] = '%';
            output[j++] = '2';
            output[j] = '0';
        }
    }

    return output;
}

int main() {
    string input = "Mr John Smith";

    string output = Urlify(input);
    cout << output << endl;
    return 0;
}
