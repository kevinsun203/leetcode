#include "vector";
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        if (intervals.size() == 0) {
            answer.push_back(newInterval);
            return answer;
        }

        int i = 0;
        int j = -1;
        vector<int> mergedInterval;

        // Search for the interval of first insertion
        while (i < intervals.size() && newInterval[0] >= intervals[i][0]) {
            answer.push_back(intervals[i]);
            i++;
        }

        if (i > 0) {
            j = i-1;
        }

        if(j >= 0 && intervals[j][1] >= newInterval[0]) {
            // insertion happens within the interval found
            mergedInterval.push_back(intervals[j][0]);
            answer.pop_back();
        } else {
            // insertion happens before the interval found or after the interval found
            mergedInterval.push_back(newInterval[0]);
            j = i;
        }


        // Search for interval of second insertion
        while (j < intervals.size() && newInterval[1] > intervals[j][1] && newInterval[1] > intervals[j][0]) {
            j++;
        }

        if (j < intervals.size() && newInterval[1] >= intervals[j][0] && newInterval[1] <= intervals[j][1]) {
            // insertion happens within the interval found
            mergedInterval.push_back(intervals[j][1]);
            j++;
        } else {
            // insertion happens before the interval found
            mergedInterval.push_back(newInterval[1]);
        }

        answer.push_back(mergedInterval);

        while (j < intervals.size()) {
            answer.push_back(intervals[j]);
            j++;
        }

        return answer;

    }
};