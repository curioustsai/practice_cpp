/*
*
* https://leetcode.com/problems/design-twitter/
*/

#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Twitter {
public:
    Twitter() {}

    void postTweet(int userId, int tweetId) { posts.push_back({userId, tweetId}); }

    vector<int> getNewsFeed(int userId) {
        int count = 0;
        vector<int> res;
        for (int i = posts.size() - 1; i >= 0; i--) {
            if (count == 10) break;
            if (map[userId].count(posts[i].first) || posts[i].first == userId) {
                count++;
                res.push_back(posts[i].second);
            }
        }
        return res;
    }

    void follow(int followerId, int followeeId) { map[followerId].insert(followeeId); }

    void unfollow(int followerId, int followeeId) { map[followerId].erase(followeeId); }

private:
    // followerID, a bunch of followeeID
    unordered_map<int, unordered_set<int>> map;
    // {userID, postID}
    vector<pair<int, int>> posts;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
