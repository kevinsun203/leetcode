#include "vector";
#include "algorithm";
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {return (a[0]==b[0]) ? a[1]<b[1] : a[0] < b[0];});
        int i = 0;
        vector<int> merged;
        int temp;
        vector<vector<int>> answer;
        while (i < intervals.size()) {
            if (i != intervals.size() - 1 && intervals[i][1] >= intervals[i+1][0]) {
                merged.push_back(intervals[i][0]);
                temp = helper(intervals, temp, i);
                merged.push_back(temp);
                answer.push_back(merged);
                merged.clear();
            } else {
                answer.push_back(intervals[i]);
            }
            i++;

        }
        return answer;
    }

    int helper(vector<vector<int>>& intervals, int endingElement, int& index) {
        if (index == intervals.size()-1|| intervals[index][1] < intervals[index+1][0]) {
            return intervals[index][1];
        } else if (intervals[index][1] > intervals[index+1][1]) {
            endingElement = intervals[index][1];
            while (index != intervals.size() && endingElement >= intervals[index][1]) {
                index++;
            }
            if (index < intervals.size() && endingElement >= intervals[index][0]) {
                return helper(intervals, endingElement, index);
            }
            index--;
            return endingElement;
        } else {
            index++;
            return helper(intervals, endingElement, index);
        }
    }
};