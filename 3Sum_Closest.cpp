#include "vector"
#include "algorithm"
#include "cmath"
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int difference = nums[0] + nums[1] + nums[2] - target;
        int tempSum, tempDiff;

        // fix first element
        for (int i=0; i<nums.size()-2; i++) {
            
            if ((nums[i] >= target && target >= 0) || nums[i] >=0 && target <= 0) {
                break;
            }
            int left = i+1;
            int right = nums.size()-1;

            // two pointers between first fixed element + 1 and last element
            while (left < right) {
                tempSum = nums[i] + nums[left] + nums[right];
                tempDiff = tempSum - target;
                if (tempDiff == 0) {
                    return target;
                } 
                difference = abs(tempDiff) < abs(difference) ? tempDiff : difference;
                if(tempDiff < 0) {
                    left++;
                } else {
                    right--;
                }
            }

        }
        return difference+target;

        
    }
};