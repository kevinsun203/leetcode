#include <vector>
#include <algorithm>

class Solution {

private:
    std::vector<std::vector<int>> answer;
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, target, 0, {});
        return answer;
    }

    void helper(std::vector<int>& candidates, int sum, int target, int index, std::vector<int> currComb) {
        if (sum > target) {
            return;
        } else if (sum == target) {
            answer.push_back(currComb);
            return;
        }

        for (int i=index; i<candidates.size(); i++) {
            currComb.push_back(candidates[i]);
            helper(candidates,sum+candidates[i], target, i, currComb);
            currComb.pop_back();
        }
        return;
    }
};