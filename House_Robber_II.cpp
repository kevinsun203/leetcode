#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        } else if (n == 2) {
            return std::max(nums[0], nums[1]);
        }
        int p = robHouses(nums, 0, n-2);
        int q = robHouses(nums, 1, n-1);

        return std::max(p,q);
    }

    int robHouses(std::vector<int>& nums, int begin, int end) {
        std::vector<int> tab(nums.size(), nums[begin]);
        if (end-begin == 0) {
            return nums[begin];
        }
        tab[begin+1] = std::max(nums[begin], nums[begin+1]);

        for (int i=begin+2; i<=end; i++) {
            tab[i] = std::max(tab[i-2] + nums[i], tab[i-1]);
        }

        return tab[end];
    }
};