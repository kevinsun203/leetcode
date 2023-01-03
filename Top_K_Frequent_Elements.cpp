#include "unordered_map"
#include "vector"
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            if (freq.find(nums[i]) == freq.end()) {
                freq[nums[i]] = 1;
            } else {
                freq[nums[i]]++;
            }
        }
        // at most, element can appear n times, so need array of n+1 size
        vector<vector<int>> bucket(n+1);
        for (auto i=freq.begin(); i!=freq.end(); i++) {
            bucket[i->second].push_back(i->first);
        }

        vector<int> answer;
        for (int i=n; i>=0; i--) {
            if (answer.size() == k) {
                break;
            } else {
                if (bucket[i].size() != 0) {
                    answer.insert(answer.end(), bucket[i].begin(), bucket[i].end());
                }
            }
        }

        return answer;
    }
};