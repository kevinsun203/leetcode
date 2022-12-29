#include "vector"
#include "algorithm"
using namespace std;

//kadane's algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int local_max = 0;
        int global_max = INT_MIN;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            local_max = max(nums[i], local_max+nums[i]);
            if (local_max > global_max) {
                global_max = local_max;
            }
        }
        return global_max;
    }
};