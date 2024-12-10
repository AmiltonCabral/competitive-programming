#include <bits/stdc++.h>
using namespace std;

class Twitter {
   public:
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> posts;
    int time = 0;

    Twitter() {}

    // O(1)
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({time, tweetId});
        ++time;
    }

    // O(n)
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        following[userId].insert(userId);

        // Add tweets from people they follow
        for (int followeeId : following[userId]) {
            for (auto& post : posts[followeeId]) {
                pq.push({post.first, post.second});
            }
        }

        vector<int> newsFeed;

        while (newsFeed.size() < 10 && !pq.empty()) {
            newsFeed.push_back(pq.top().second);
            pq.pop();
        }

        return newsFeed;
    }

    // O(1)
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    // O(1)
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

int main() {
    Twitter tt = Twitter();
    tt.postTweet(1, 5);
    tt.postTweet(1, 3);

    for (int post : tt.getNewsFeed(1)) {
        cout << post << " ";
    }
    cout << endl;
}
