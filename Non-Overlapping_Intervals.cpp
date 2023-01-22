#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 1) {
            return 0;
        }

        sort(intervals.begin(), intervals.end());
        int answer = 0;
        int idx = 0;
        int upperBound = intervals[0][1];
        while(idx < n-1) {
            if (upperBound > intervals[idx+1][0]) {
                answer++;
                upperBound = min(upperBound, intervals[idx+1][1]);
            } else {
                upperBound = intervals[idx+1][1];
            }
            idx++;
        }
        return answer;

    }
};