#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> difference;
        int n = gas.size();
        int sum = 0;
        int tempSum = 0;
        
        // gas-cost array
        for (int i=0; i<n; i++) {
            tempSum = gas[i]-cost[i];
            difference.push_back(tempSum);
            sum += tempSum;
        }

        // If total sum of gas-cost array is less than 0, no complete circuit can be found
        if (sum < 0) {
            return -1;
        }

        // find first index of last non-negative sum subarray
        int local_max = 0;
        int firstIndex = 0;
        for (int i=0; i<n; i++) {
            if (difference[i] >= difference[i] + local_max) {
                local_max = difference[i];
                firstIndex = i;
            } else {
                local_max = difference[i] + local_max;
            }
        }

        return firstIndex;

    }
};