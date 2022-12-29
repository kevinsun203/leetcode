#include "vector"
#include "unordered_map"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> elems;
        vector<int> answer;

        for (int i=0; i<nums.size(); i++) {
            elems[nums[i]].push_back(i);
    
        }

        for (int i=0; i<nums.size(); i++) {
            int needed = target - nums[i];
            if (elems.find(needed) != elems.end()) {
                if (needed == nums[i] && elems[nums[i]].size() == 2) {
                    return {i, elems[nums[i]].back()};
                } else if (needed != nums[i]){
                    return {i, elems[needed].back()};
                }
            }
        }
        return answer;
    }
};