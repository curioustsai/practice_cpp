/*
* You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight.
* Reconstruct the itinerary in order and return it. All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK".
* If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.
* For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
* You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.
*
* https://leetcode.com/problems/reconstruct-itinerary/
*/

#include <gtest/gtest.h>

#include <algorithm>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (int i = 0; i < tickets.size(); i++) { m[tickets[i][0]].insert(tickets[i][1]); }

        vector<string> result;
        dfs("JFK", result);
        reverse(result.begin(), result.end());
        return result;
    }

private:
    unordered_map<string, set<string>> m;
    void dfs(string airport, vector<string>& result) {

        while (!m[airport].empty()) {
            string next = *m[airport].begin();
            m[airport].erase(m[airport].begin());
            dfs(next, result);
        }
        result.push_back(airport);
    }
};

TEST(FindItinerary, Example1) {
    vector<vector<string>> tickets = {
        {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    vector<string> output = {"JFK", "MUC", "LHR", "SFO", "SJC"};

    Solution sol;

    ASSERT_EQ(sol.findItinerary(tickets), output);
}
