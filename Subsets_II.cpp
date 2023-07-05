#include <vector>
#include <algorithm>

class Solution {
private:
    std::vector<std::vector<int>> answer;
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        answer.push_back({});
        sort(nums.begin(), nums.end());
        helper(nums, {}, 0);
        return answer;
    }


    void helper(std::vector<int>& nums, std::vector<int> curr, int index) {
        if (index == nums.size()) {
            // max length subset built
            return;
        }

        for (int i=index; i<nums.size(); i++) {
            curr.push_back(nums[i]);
            answer.push_back(curr);
            helper(nums, curr, i+1);
            curr.pop_back();
            // Skip to the next unique element
            while (i<nums.size()-1 && nums[i] == nums[i+1]) {
                i++;
            }
        }

        return;
    }
};