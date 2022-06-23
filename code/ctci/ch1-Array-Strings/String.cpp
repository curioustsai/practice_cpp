#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>

/*
 * Concatenation: +operator
 * String length: length()
 * Search: find()
 * Substrings: substr()
 * Replace: replace()
 * Insert: insert()
 * Erase: erase()
 * split
 * join
 * strip
 * upper
 * lower
 */

using namespace std;

const std::string WHITESPACE = " \n\r\t\f\v";

vector<string> split(const string& str, const string& tok) {
    vector<string> result;
    string::size_type begin = 0;
    string::size_type end = str.find(tok);

    while (end != string::npos) {
        if (end - begin != 0) { result.push_back(str.substr(begin, end - begin)); }
        begin = end + tok.size();
        end = str.find(tok, begin);
    }

    if (begin != str.length()) { result.push_back(str.substr(begin)); }

    return result;
}

string reverseString(const string& input) {
    string result = input;

    int i = 0;
    int j = input.length() - 1;

    while (i < j) {
        char temp = result[i];
        result[i] = result[j];
        result[j] = temp;
        i++;
        j--;
    }

    return result;
}

string ltrim(const string& input) {
    size_t start = input.find_first_not_of(WHITESPACE);
    return (start == string::npos) ? "" : input.substr(start);
}

string rtrim(const string& input) {
    size_t end = input.find_last_not_of(WHITESPACE);
    return (end == string::npos) ? "" : input.substr(0, end + 1);
}

string trim(const string& input) { return ltrim(rtrim(input)); }

string join(vector<string> input, string token) {
    string concat;
    string res;
    for (string& s : input) { concat = concat + s + token; }
    res = trim(concat);
    return res;
}

// for ascii code, upper alpha is smaller than lower alpha
string upperString(const string& input) {
    string res = input;
    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] >= 'a' && input[i] <= 'z') { res[i] -= 'a' - 'A'; }
    }
    return res;
}

string lowerString(const string& input) {
    string res = input;
    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') { res[i] += 'a' - 'A'; }
    }
    return res;
}

TEST(String, trim) {
    string test1 = " 123 ";
    ASSERT_EQ(ltrim(test1), "123 ");
    ASSERT_EQ(rtrim(test1), " 123");
    ASSERT_EQ(trim(test1), "123");

    string test2 = "abc";
    ASSERT_EQ(ltrim(test2), "abc");
    ASSERT_EQ(rtrim(test2), "abc");
    ASSERT_EQ(trim(test2), "abc");
}

TEST(String, split) {
    string str1 = "Hello World, This is Richard";
    vector<string> res = split(str1, " ");

    for (string i : res) { cout << i << endl; }
}

TEST(String, reverse) {
    string input = "abcdefg";
    string res = reverseString(input);
    ASSERT_EQ(res, "gfedcba");

    string input2 = "abcdefgh";
    string res2 = reverseString(input2);
    ASSERT_EQ(res2, "hgfedcba");
}

TEST(String, join) {
    vector<string> test = {"Hello", "Fortemedia", "and", "Goodbye", "FM"};
    string res = join(test, " ");
    cout << res << endl;
    ASSERT_EQ(res, "Hello Fortemedia and Goodbye FM");
}

TEST(String, upper) {
    string test = "!@#$ AbCdE";
    ASSERT_EQ(upperString(test), "!@#$ ABCDE");
}

TEST(String, lower) {
    string test = "!@#$ AbCdE";
    ASSERT_EQ(lowerString(test), "!@#$ abcde");
}
