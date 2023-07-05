#include <vector>

class Solution {
private:
    std::vector<std::vector<int>> answer;
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        answer.push_back({});
        helper(nums, {}, 0);
        return answer;
    }

    void helper(std::vector<int>& nums, std::vector<int> curr, int index) {
        if (index == nums.size()) {
            // max subset built
            return;
        }

        for (int i=index; i<nums.size(); i++) {
            curr.push_back(nums[i]);
            answer.push_back(curr);
            helper(nums, curr, i+1);
            curr.pop_back();
        }

        return;
    }
};