#include "vector"
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        return helper(nums, 0, nums.size()-1);
    }

    int helper(vector<int>& nums, int begin, int end) {
        int median = (begin+end)/2;
        //subarray is sorted
        if (nums[median] >= nums[begin] && nums[median] <= nums[end]) {
            return nums[begin];
        } 
        // min element found
        else if (median-1>=begin && nums[median]<nums[median-1]) {
            return nums[median];
        } 
        
        else if (nums[median]>nums[end]) {
            return helper(nums, median+1, end);
        } else {
            return helper(nums, begin, median-1);
        }
    }
};