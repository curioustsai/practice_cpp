/*
* https://leetcode.com/problems/merge-triplets-to-form-target-triplet/description/
*/
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<vector<int>> cands;
        for (vector<int> triplet: triplets) {
            if (triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2])
                continue;
            cands.push_back(triplet);
        }

        set<int> s;
        for (vector<int> cand: cands) {
            for (int i = 0; i < 3; i++) {
                if (cand[i] == target[i])
                    s.insert(i);
            }
        }
        return s.size() == 3;
    }
};
