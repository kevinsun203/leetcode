#include "map";
#include "vector";
#include "algorithm";
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        map <int, int> elems;
        for (int i=0; i<nums.size(); i++) {
            elems[nums[i]] = i;
        }
        vector <int> triplet;
        vector <vector<int>> answer;

        for (int i=0; i<nums.size()-2; i++) {
            if (nums[i] > 0) {
                break;
            }
            for (int j=i+1; j<nums.size()-1; j++) {
                int numNeeded = 0 - nums[j] - nums[i];
                if (elems.count(numNeeded) && elems.find(numNeeded)->second > j) {
                    triplet = {nums[i],nums[j],numNeeded};
                    answer.push_back(triplet);
                }
                // set second fixed element to the last occurrence in order to avoid duplicates
                j = elems.find(nums[j])->second;

            }

            // set first fixed element to the last occurrence in order to avoid duplicates
            i = elems.find(nums[i])->second;
        }
        return answer;
    }
};