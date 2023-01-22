#include "vector";
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int idx = 0;
        vector<vector<int>> answer;

        // find overlap
        while (idx < n && intervals[idx][1] < newInterval[0]) {
            answer.push_back(intervals[idx]);
            idx++;
        }

        // merge overlapping intervals
        while (idx < n && intervals[idx][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[idx][0]);
            newInterval[1] = max(newInterval[1], intervals[idx][1]);
            idx++;
        }

        answer.push_back(newInterval);
        while (idx < n) {
            answer.push_back(intervals[idx]);
            idx++;
        }

        return answer;
    }
};