#include <vector>
#include <queue>
#include <limits.h>

struct compare {
    bool operator()(std::pair<int, int> a, std::pair<int, int> b) {
        return a.second > b.second;         
    }
};

class Solution {
public:
    // Djikstra's
    int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, compare> q;
        std::vector<std::vector<std::pair<int, int>>> adjacencyList(n+1, std::vector<std::pair<int, int>>(0));
        std::vector<int> visited(n+1, -1);
        std::vector<int> distances(n+1, INT_MAX);
        distances[0] = 0;
        distances[k] = 0;

        // Create adjacency list representation of the network
        for (int i=0; i<times.size(); i++) {
            adjacencyList[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        // Push starting node into the queue
        q.push({k, 0});

        int numVisited = 0;

        while (!q.empty()) {
            std::pair<int, int> curr = q.top();
            q.pop();

            if (visited[curr.first] == 0) {
                continue;
            }
            // mark node as visited
            visited[curr.first] = 0;
            numVisited++;

            if (numVisited == n) {
                break;
            }

            // loop through all adjacent nodes
            std::vector<std::pair<int, int>> neighbours = adjacencyList[curr.first];

            for (int i=0; i<neighbours.size(); i++) {
                int distance = curr.second + neighbours[i].second;
                if (distance < distances[neighbours[i].first]) {
                    distances[neighbours[i].first] = distance;
                    q.push({neighbours[i].first, distance});
                }
            }
        }

        // Find the greatest element out of all the distances
        int answer = INT_MIN;
        for (int i=0; i<distances.size(); i++) {
            if (distances[i] > answer) {
                answer = distances[i];
            }
        }

        if (answer == INT_MAX) {
            return -1;
        } else {
            return answer;
        }

    }
};