/*
Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:
string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}

Machine 2 (receiver) has the function:
vector<string> decode(string s) {
  //... your code
  return strs;
}
 

So Machine 1 does:
string encoded_string = encode(strs);
 

and Machine 2 does:
vector<string> strs2 = decode(encoded_string);

strs2 in Machine 2 should be the same as strs in Machine 1.
Implement the encode and decode methods.

Note:
The string may contain any possible characters out of 256 valid ascii characters. Your algorithm should be generalized enough to work on any possible characters.
Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
Do not rely on any library method such as eval or serialize methods. You should implement your own encode/decode algorithm.
*/

#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string encode(vector<string> strs) {
        if (strs.size() == 0) return "";
        string result;
        for (string str : strs) { result += to_string(str.length()) + str + ":"; }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        if (s.size() == 0) return result;

        int i = 0;
        while (i < s.length()) {
            // TODO: error handle
            int j = i;
            while (isdigit(s[j])) j++;
            int len = stoi(s.substr(i, j - i));
            string word = s.substr(j, len);
            result.push_back(word);
            i = j + len + 1;
        }

        return result;
    }
};

TEST(CodecString, Example1) {
    Solution sol;
    vector<string> input = {"Richard", "is", "a", "handsome", "guy"};
    string encode_ans = "7Richard:2is:1a:8handsome:3guy:";
    string encode = sol.encode(input);
    vector<string> decode = sol.decode(encode);

    ASSERT_EQ(sol.encode(input), encode_ans);
}

TEST(CodecString, Example2) {
    Solution sol;
    vector<string> input = {"RichardTsai", "is", "a", "handsome", "guy"};
    string encode_ans = "11RichardTsai:2is:1a:8handsome:3guy:";
    string encode = sol.encode(input);
    vector<string> decode = sol.decode(encode);

    ASSERT_EQ(sol.encode(input), encode_ans);
}
