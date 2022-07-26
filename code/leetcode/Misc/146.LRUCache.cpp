/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache.
If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

https://leetcode.com/problems/lru-cache/
https://leetcode.com/problems/lru-cache/discuss/45912/Clean-Short-Standard-C%2B%2B-solution-NOT-writing-C-in-C%2B%2B-like-all-other-lengthy-ones
*/

#include <gtest/gtest.h>

#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity) {}

    int get(int key) {
        auto it = um.find(key);
        // key doesn't exists
        if (it == um.end()) { return -1; }
        // update list
        l.splice(l.begin(), l, it->second);
        //return value
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = um.find(key);
        // key exists
        if (it != um.end()) {
            l.splice(l.begin(), l, it->second);
            it->second->second = value;
            return;
        }
        // key doens't exists
        if (l.size() == _capacity) {
            // full, remove the oldeset
            int key = l.back().first;
            l.pop_back();
            um.erase(key);
        }

        l.push_front(pair<int, int>(key, value));
        um[key] = l.begin();
    }

private:
    int _capacity{0};
    unordered_map<int, list<pair<int, int>>::iterator> um;
    list<pair<int, int>> l;
};

TEST(LRUCache, Example1) {
    LRUCache *lRUCache = new LRUCache(2);
    lRUCache->put(1, 1);             // cache is {1=1}
    lRUCache->put(2, 2);             // cache is {1=1, 2=2}
    ASSERT_EQ(lRUCache->get(1), 1);  // return 1
    lRUCache->put(3, 3);             // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    ASSERT_EQ(lRUCache->get(2), -1); // returns -1 (not found)
    lRUCache->put(4, 4);             // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    ASSERT_EQ(lRUCache->get(1), -1); // return -1 (not found)
    ASSERT_EQ(lRUCache->get(3), 3);  // return 3
    ASSERT_EQ(lRUCache->get(4), 4);  // return 4;

    delete lRUCache;
}
