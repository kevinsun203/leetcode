#include "vector";
#include "algorithm";
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 1) {
            return intervals;
        }
        // sort in ascending order based on first element of each interval
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {return (a[0]==b[0]) ? a[1]<b[1] : a[0] < b[0];});
        int idx = 0;
        vector<vector<int>> answer;

        vector<int> temp = intervals[0];
        while (idx < n-1) {
            if (temp[1] >= intervals[idx+1][0]) {
                temp[0] = min(intervals[idx+1][0], temp[0]);
                temp[1] = max(intervals[idx+1][1], temp[1]);
            } else {
                answer.push_back(temp);
                temp = intervals[idx+1];
            }
            idx++;
        }
        answer.push_back(temp);
        return answer;
    }

};