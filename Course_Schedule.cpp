#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        if (prerequisites.size() == 1 || prerequisites.size() == 0) {
            return true;
        } 
        std::vector<std::vector<int>> graph(numCourses); // maps a course to its requisite courses
        std::vector<int> numPrereqs(numCourses, 0); // see how many prerequisite courses are required
        for (int i=0; i<prerequisites.size(); i++) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            numPrereqs[prerequisites[i][0]]++;
        }

        std::queue<int> q;
        // push all courses that don't have prerequisites
        for (int i=0; i<numCourses; i++) {
            if (numPrereqs[i] == 0) {
                q.push(i);
            }
        }

        int completedCourses = 0;
        while (!q.empty()) {
            int it = q.front();
            q.pop();
            completedCourses++;

            std::vector<int> requisiteCourses = graph[it];

            for (int i=0; i<requisiteCourses.size(); i++) {
                numPrereqs[requisiteCourses[i]]--; // prereq completed
                if (numPrereqs[requisiteCourses[i]] == 0) { // push course if all prerequisites have been completed
                    q.push(requisiteCourses[i]);
                }
            }
        }
        if (completedCourses == numCourses) {
            return true;
        }
        return false;
        
    }
};