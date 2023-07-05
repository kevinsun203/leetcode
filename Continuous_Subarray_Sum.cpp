#include <unordered_map>
#include <vector>

class Solution {
public:
    bool checkSubarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> remainders;
        remainders[nums[0] % k] = 0;
        int totalSum = nums[0];

        int len = nums.size();
        for (int i=1; i<len; i++) {
            totalSum += nums[i];

            // If the accumulated sum is a perfect multiple of k
            if (totalSum % k == 0) {
                return true;
            }

            // If there already exists a prefix sum whose remainder sum % k is equal to the current remainder
            if (remainders.find(totalSum % k) != remainders.end()) {
                if (i - remainders[totalSum % k] >= 2) {
                    return true;
                }
            }

            if (remainders.find(totalSum % k) == remainders.end()) {
                remainders[totalSum % k] = i;
            }
        }
        return false;
    }
};