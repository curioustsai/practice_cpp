/*
Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name,
and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts.
Note that even if two accounts have the same name, they may belong to different people as people could have the same name.
A person can have any number of accounts initially, but all of their accounts definitely have the same name.
After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order.
The accounts themselves can be returned in any order.

https://leetcode.com/problems/accounts-merge/
*/

#include <gtest/gtest.h>

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> m;
        vector<int> union_find(accounts.size(), 0);
        unordered_map<int, vector<string>> res_map;

        for (int i = 0; i < accounts.size(); i++) {
            union_find[i] = i;
            for (int j = 1; j < accounts[i].size(); j++) {
                if (m.find(accounts[i][j]) != m.end()) {
                    int root1 = find(union_find, i);
                    int root2 = find(union_find, m[accounts[i][j]]);
                    // keep track its parent
                    union_find[root1] = root2;
                } else
                    // since in union i, use union_find[i]
                    m[accounts[i][j]] = union_find[i];
            }
        }

        for (auto it : m) {
            int ind = find(union_find, it.second);
            res_map[ind].push_back(it.first);
        }

        vector<vector<string>> res;
        for (auto it : res_map) {
            vector<string> email = it.second;
            sort(email.begin(), email.end());
            email.insert(email.begin(), accounts[it.first][0]);
            res.push_back(email);
        }

        sort(res.begin(), res.end(),
             [](vector<string>& a, vector<string>& b) { return a[0] < b[0]; });

        return res;
    }

private:
    int find(vector<int>& union_find, int ind) {
        while (union_find[ind] != ind) ind = union_find[ind];
        return ind;
    }
};

TEST(AccountMerge, Example1) {
    vector<vector<string>> accounts = {{"John", "johnsmith@mail.com", "john_newyork@mail.com"},
                                       {"John", "johnsmith@mail.com", "john00@mail.com"},
                                       {"Mary", "mary@mail.com"},
                                       {"John", "johnnybravo@mail.com"}};
    vector<vector<string>> ans = {
        {"John", "john00@mail.com", "john_newyork@mail.com", "johnsmith@mail.com"},
        {"John", "johnnybravo@mail.com"},
        {"Mary", "mary@mail.com"}};
    Solution sol;
    ASSERT_EQ(sol.accountsMerge(accounts), ans);
}

TEST(AccountMerge, Example2) {
    {
        vector<vector<string>> accounts = {{"Gabe", "Gabe0@m.co", "Gabe3@m.co", "Gabe1@m.co"},
                                           {"Kevin", "Kevin3@m.co", "Kevin5@m.co", "Kevin0@m.co"},
                                           {"Ethan", "Ethan5@m.co", "Ethan4@m.co", "Ethan0@m.co"},
                                           {"Hanzo", "Hanzo3@m.co", "Hanzo1@m.co", "Hanzo0@m.co"},
                                           {"Fern", "Fern5@m.co", "Fern1@m.co", "Fern0@m.co"}};

        vector<vector<string>> ans = {{
            {"Ethan", "Ethan0@m.co", "Ethan4@m.co", "Ethan5@m.co"},
            {"Fern", "Fern0@m.co", "Fern1@m.co", "Fern5@m.co"},
            {"Gabe", "Gabe0@m.co", "Gabe1@m.co", "Gabe3@m.co"},
            {"Hanzo", "Hanzo0@m.co", "Hanzo1@m.co", "Hanzo3@m.co"},
            {"Kevin", "Kevin0@m.co", "Kevin3@m.co", "Kevin5@m.co"},
        }};
        Solution sol;
        ASSERT_EQ(sol.accountsMerge(accounts), ans);
    }
}
