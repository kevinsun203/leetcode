#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int answer = nums[0];

        if (nums.size() == 1) {
            return nums[0];
        }

        int localMax = nums[0];
        int localMin = nums[0];

        // Must maintain local minimum (negative number)
        for (int i=1; i<nums.size(); i++) {
            int tempMin = localMin;
            int tempMax = localMax;
            localMin = std::min({nums[i], localMax*nums[i], localMin*nums[i]});
            localMax = std::max({nums[i], tempMax*nums[i], tempMin*nums[i]});
            if (localMax > answer) {
                answer = localMax;
            }
        }

        return answer;

    }
};