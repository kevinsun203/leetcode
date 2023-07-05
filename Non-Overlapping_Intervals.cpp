#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int answer = 0;

        int idx = 1;
        int upperBound = intervals[0][1];
        while (idx < n) {
            // Remove larger interval
            if (upperBound > intervals[idx][0]) {
                answer++;
                upperBound = min(upperBound, intervals[idx][1]);
            } else {
                upperBound = intervals[idx][1];
            }
            idx++;
        }

        return answer;
    }
};