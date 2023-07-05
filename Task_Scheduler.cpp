#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        // Get frequency of each task
        std::unordered_map<char, int> freq;
        for (int i=0; i<tasks.size(); i++) {
            if (freq.find(tasks[i]) == freq.end()) {
                freq.insert({tasks[i], 1});
            } else {
                freq[tasks[i]]++;
            }
        }

        // Insert elements into a priority queue with most frequent tasks first
        std::priority_queue<int> q;
        for (auto i=freq.begin(); i!=freq.end(); i++) {
            q.push(i->second);
        }

        // We create a queue to keep track of when a task is ready to be re-inserted
        // each associated int is the timestep at which a task is ready to be re-inserted
        std::queue<std::pair<int, int>> reQ;

        int timeStep = 0;
        while (!q.empty() || !reQ.empty()) {

            // Process task if available
            if (!q.empty()) {
                int task = q.top(); 
                q.pop();

                // insert into insertion queue if tasks not all complete
                if (task > 1) {
                    std::pair<char, int> toInsert = {task-1, timeStep + n};
                    reQ.push(toInsert);
                }

            }
            // Re-insert from the insertion queue
            if (!reQ.empty()) {
                std::pair<int, int> nextTask = reQ.front();
                if (nextTask.second == timeStep) {
                    q.push(nextTask.first);
                    reQ.pop();
                }
            }

            timeStep++;
        }

        return timeStep;

    }
};