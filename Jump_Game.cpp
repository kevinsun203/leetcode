#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int n = nums.size();
        int reachable = 0; // maximum reachable distance

        for (int i=0; i<n; i++) {
            if (i > reachable) {
                // We've reached an index that isn't reachable
                return false;
            }

            if (nums[i]+i > reachable) {
                reachable = nums[i] + i;
            }

            if (reachable >= n-1) {
                return true;
            }
        }

        return false;
    }
};