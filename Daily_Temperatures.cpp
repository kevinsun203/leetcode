#include "vector"
#include "stack"
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stck;
        vector<int> answer(temperatures.size(), 0);
        int n = temperatures.size();

        for (int i=0; i<n; i++) {
            while (!stck.empty() && temperatures[i] > stck.top().first) {
                answer[stck.top().second] = i-stck.top().second;
                stck.pop();
            }
            stck.push({temperatures[i], i});
        }
        return answer;
    }
};