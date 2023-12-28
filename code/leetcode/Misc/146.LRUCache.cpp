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
    // <key, iterator>
    unordered_map<int, list<pair<int, int>>::iterator> um;
    // <key, value>
    list<pair<int, int>> l;
};

class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), value(v) {
        prev = nullptr;
        next = nullptr;
    };
};

/*
 * Hash map + doubly linked list, left = LRU, right = MRU 
 * get: update to MRU, put: update to MRU, remove LRU if full 
 *
 * Time: O(1) Space: O(capacity) 
 */

class LRUCache2 {
public:
    LRUCache2(int capacity) {
        cap = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);

        left->next = right;
        right->prev = left;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
            delete (cache[key]);
        }
        cache[key] = new Node(key, value);
        insert(cache[key]);

        if (cache.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete (lru);
        }
    }

private:
    unordered_map<int, Node*> cache;
    int cap;
    Node* left;
    Node* right;

    void insert(Node* node) {
        Node* prev = right->prev;
        Node* next = right;

        prev->next = node;
        next->prev = node;

        node->prev = prev;
        node->next = next;
    }

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

TEST(LRUCache, Example1) {
    LRUCache* lRUCache = new LRUCache(2);
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
