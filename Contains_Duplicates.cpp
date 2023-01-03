#include "unordered_set"
#include "vector"
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> freq;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            if (freq.find(nums[i]) != freq.end()) {
                return true;
            } else {
                freq.insert(nums[i]);
            }
        }
        return false;
    }
};