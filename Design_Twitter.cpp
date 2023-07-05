#include <set>
#include <map>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

// Better way to keep a vector of all tweets and iterate starting from the end, seeing if the tweet
// is from a followee

struct user {
    int userId;
    std::unordered_set<int> follows; // The users that this user follows
    std::vector<std::pair<int, int>> tweets; // The tweets that a user has created along
                                             // w/ their timestamp
    user(int user) : userId(user), follows({user}){}
};

class Twitter {

private:
    std::unordered_map<int, user*> users; // keep track of all users, their followers and tweets
    int timeStep;

public:
    Twitter() {
        timeStep = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        // Create user if not present
        if (users.find(userId) == users.end()) {
            users[userId] = new user(userId);
        }

        users[userId]->tweets.push_back({tweetId, timeStep});
        timeStep++;
        return;
    }
    
    std::vector<int> getNewsFeed(int userId) {
        // Merge all the tweets of the users that the userId follows
        if (users.find(userId) == users.end()) {
            return {};
        }

        std::unordered_set<int> followedUsers = users[userId]->follows;

        std::vector<int> tweets;
        std::vector<std::pair<int, int>> allTweets;
        for (auto i=followedUsers.begin(); i!=followedUsers.end(); i++) {
            allTweets.insert(allTweets.end(), users[*i]->tweets.begin(), users[*i]->tweets.end());
        }

        // sort based on timestamp
        sort(allTweets.begin(), allTweets.end(), [](std::pair<int, int> a, std::pair<int, int> b) {
            return a.second > b.second;
        });

        for (int i=0; i<allTweets.size(); i++) {
            tweets.push_back(allTweets[i].first);
        }
        int maxIndex = tweets.size() >= 10 ? 10 : tweets.size();
        std::vector<int> answer(tweets.begin(), tweets.begin() + maxIndex);
        return answer;
    }
    
    void follow(int followerId, int followeeId) {
        // Add followee to follower's set

        // create users if not yet existent
        if (users.find(followerId) == users.end()) {
            users[followerId] = new user(followerId);
        }

        if (users.find(followeeId) == users.end()) {
            users[followeeId] = new user(followeeId);
        }

        // Add new folowee
        users[followerId]->follows.insert(followeeId);

        return;
    }
    
    void unfollow(int followerId, int followeeId) {
        // Remove followee

        // create users if not yet existent
        if (users.find(followerId) == users.end()) {
            users[followerId] = new user(followerId);
        }

        if (users.find(followeeId) == users.end()) {
            users[followeeId] = new user(followeeId);
        }

        users[followerId]->follows.erase(followeeId);
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