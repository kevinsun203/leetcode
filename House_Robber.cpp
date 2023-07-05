#include <vector>
#include <algorithm>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        std::vector<int> tab(nums.size(), nums[0]);
        if (nums.size() == 1) {
            return nums[0];
        }
        tab[1] = std::max(nums[1], nums[0]);

        for (int i=2; i<nums.size(); i++) {
            tab[i] = std::max(tab[i-2] + nums[i], tab[i-1]);
        }

        return tab[nums.size()-1];
    }
};