#include <vector>
#include <algorithm>

class Solution {
private:
    std::vector<std::vector<int>> answer;
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        std::vector<int> curr;
        helper(candidates, 0, 0, target, curr);
        return answer;
    }

    void helper(std::vector<int>& candidates, int index, int sum, int target, std::vector<int>& currCombination) {

        if (sum == target) {
            answer.push_back(currCombination);
            return;
        }

        if (sum > target) {
            return;
        }

        int n = candidates.size();
        for (int i=index; i<n; i++) {
            currCombination.push_back(candidates[i]);
            helper(candidates, i+1, sum+candidates[i], target, currCombination);
            currCombination.pop_back();
            while (i<n-1 && candidates[i] == candidates[i+1]) {
                i++;
            }
        }
        return;
    }
};