#include "vector";
using namespace std;
#include "iostream";

// Note: An O(n) solution that just iterates through the array seems to pass all the cases as well but doesn't meet 
// the time complexity requirement of the problem.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums[0] == target) {
            return 0;
        }

        // Search for the index of the minimum value 
        int minIndex = searchIndex(nums, 0, nums.size()-1);

        // Run binary search on the left or right subarray
        if (nums[minIndex] <= target && nums[nums.size()-1] >= target) {
            return binarySearch(nums, minIndex, nums.size()-1, target);
        } else {
            return binarySearch(nums, 0, minIndex-1, target);
        }
    }
    int binarySearch(vector<int>& nums, int begin, int end, int target) {
        int median = (begin + end) / 2;
        if (begin > end) {
            return -1;
        }
        
        if (nums[median] == target) {
            return median;
        } else if (target<nums[median]) {
            return binarySearch(nums, begin, median-1, target);
        } else {
            return binarySearch(nums, median+1, end, target);

        }
    }
     
    int searchIndex(vector<int>& nums, int begin, int end) {
        int median = (begin + end) / 2;
        
        if (nums[end] >= nums[median] && nums[begin] <= nums[median]) {
            return begin;
        } else if(median-1 >= begin && nums[median] < nums[median-1]) {
            return median;
        } else if(nums[median] > nums[end]) {
            return searchIndex(nums, median+1, end);
        } else {
            return searchIndex(nums, begin, median-1);
        }
    }
};


