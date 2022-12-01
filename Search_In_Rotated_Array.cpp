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
        // Search for the ending index of the first subarray
        // if the array has been rotated
        int median = (nums.size()-1)/2;
        int medianElement = nums[median];
        int lastElement = nums[nums.size()-1];
        int firstElement = nums[0];
        int endingFirstArray = nums.size()-1;

        if (firstElement > medianElement) {
            endingFirstArray = searchIndex(nums, 0, median, medianElement, true);
        } else if (lastElement < medianElement) {
            endingFirstArray = searchIndex(nums, median, nums.size()-1, medianElement, false);
        }
        cout << endingFirstArray << endl;
        
        // Run binary search on both subarrays
        int answer = binarySearch(nums, 0, endingFirstArray, target);
        if (answer == -1 && endingFirstArray != nums.size()-1) {
            answer= binarySearch(nums, endingFirstArray+1, nums.size()-1, target);
        }
        return answer;


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
    
    // If the function is called, then the array has definitely been rotated
    int searchIndex(vector<int>& nums, int begin, int end, int medianElement, bool left) {
        int median = (begin + end) / 2;
        if (end - begin == 1) {
            return begin;
        }
        
        if (nums[median-1]>nums[median]) {
            return median-1;
        } else if(medianElement < nums[median] && !left) {
            return searchIndex(nums, median, end, medianElement, false);
        } else if(medianElement > nums[median] && !left) {
            return searchIndex(nums, (nums.size()-1)/2,median, medianElement, false);
        } else if (medianElement < nums[median] && left) {
            return searchIndex(nums, median, end, medianElement, true);
        } else {
            return searchIndex(nums, begin,median, medianElement, true);
        }
    }
};


