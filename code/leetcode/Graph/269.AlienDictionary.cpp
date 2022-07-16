/*
There is a new alien language which uses the latin alphabet.
However, the order among letters are unknown to you.
You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language.
Derive the order of letters in this language.

keyword: topological sort

https://medium.com/@ChYuan/leetcode-269-alien-dictionary-%E5%BF%83%E5%BE%97-hard-7b04656b7569
https://www.tutorialspoint.com/alien-dictionary-in-cplusplus
*/
#include <gtest/gtest.h>

#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        // build graph and indegree
        map<char, int> degree;
        map<char, vector<char>> graph;
        int n = words.size();
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) { degree[words[i][j]] = 0; }
        }
        for (int i = 0; i < n - 1; i++) {
            int l = min((int)words[i].size(), (int)words[i + 1].size());
            for (int j = 0; j < l; j++) {
                char x = words[i][j];
                char y = words[i + 1][j];
                if (x != y) {
                    graph[x].push_back(y);
                    degree[y]++;
                    break;
                }
            }
        }
        string ret = "";
        queue<char> q;
        map<char, int>::iterator it = degree.begin();
        // start with those 0 indegree points
        while (it != degree.end()) {
            if (it->second == 0) { q.push(it->first); }
            it++;
        }

        while (!q.empty()) {
            char x = q.front();
            q.pop();
            ret += x;
            vector<char>::iterator sit = graph[x].begin();
            while (sit != graph[x].end()) {
                degree[*sit]--;
                if (degree[*sit] == 0) { q.push(*sit); }
                sit++;
            }
        }
        return ret.size() == degree.size() ? ret : "";
    }
};

TEST(AlienDictionary, Example1) {
    Solution sol;
    vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};
    ASSERT_EQ(sol.alienOrder(words), "wertf");
}
