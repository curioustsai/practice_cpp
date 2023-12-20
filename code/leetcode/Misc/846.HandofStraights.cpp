/*
* Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.
* Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.
*
* https://leetcode.com/problems/hand-of-straights/
*/

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0)
            return false;
        
        map<int, int> map;
        for (int h: hand) {
            map[h]++;
        }

        while(!map.empty()){
            int curr = map.begin()->first;
            for (int i = 0; i < groupSize; i++) {
                if (map[curr+i] == 0)
                    return false;
                map[curr+i]--;
                if (map[curr+i] == 0)
                    map.erase(curr+i);
            }
        }
        return true;
    }
};
