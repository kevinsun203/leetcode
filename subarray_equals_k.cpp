#include <unordered_map>
#include <vector>

// Use array to keep track of all prefix sums. Iterate through the prefix array
// and find whether or not k can be obtained by prefixArray[i] - prefixArray[n]
// where n < i
class Solution {
public:

    int subarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> prefixes;
        int length = nums.size();
        std::vector<int> prefixArray(length, nums[0]);
        int answer = 0;

        for (int i=1; i<length; i++) {
            prefixArray[i] = prefixArray[i-1] + nums[i];
        }

        for (int i=0; i<length; i++) {
            if (prefixArray[i] == k) {
                answer++;
            }
            
            int required = prefixArray[i] - k;
            if (prefixes.find(required) != prefixes.end()) {
                answer += prefixes[required];
            }   

            if (prefixes.find(prefixArray[i]) != prefixes.end()) {
                prefixes[prefixArray[i]] += 1;
            } else {
                prefixes[prefixArray[i]] = 1;
            }
        }
        return answer;

    }
};