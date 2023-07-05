#include <vector>
#include <unordered_set>

class Solution {
private:
    std::vector<std::vector<int>> solution;
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::unordered_set<int> usedNums; // Keep track of which numbers have been used in each recursive iteration
        std::vector<int> perm;
        helper(nums, usedNums, perm);
        return solution;
    }

    void helper(std::vector<int>& nums, std::unordered_set<int> used,std::vector<int> perm) {
        if (perm.size() == nums.size()) {
            solution.push_back(perm);
            return;
        }
        
        // backtrack
        for (int i=0; i<nums.size(); i++) {
            if (used.find(i)== used.end()) {
                perm.push_back(nums[i]);
                used.insert(i);
                helper(nums, used, perm);
                perm.pop_back();
                used.erase(i);
            }
        }
    }
};