/*
Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

TimeMap() Initializes the object of the data structure.
void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp.
If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".

https://leetcode.com/problems/time-based-key-value-store/

Solution:
https://leetcode.com/problems/time-based-key-value-store/discuss/226664/C%2B%2B-3-lines-hash-map-%2B-map
*/

#include <gtest/gtest.h>

#include <iterator>
#include <unordered_map>

using namespace std;

class TimeMap {
public:
    TimeMap() {}

    void set(string key, string value, int timestamp) { m[key].insert({timestamp, value}); }

    string get(string key, int timestamp) {
        auto it = m[key].upper_bound(timestamp);
        return it == m[key].begin() ? "" : prev(it)->second;
    }

private:
    unordered_map<string, map<int, string>> m;
};
