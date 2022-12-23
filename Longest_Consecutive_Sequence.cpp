#include "unordered_set"
#include "vector"
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> elems;
        int n = nums.size();
        if (n == 0 || n == 1) {
            return n;
        }
        for (int i=0; i<n; i++) {
            elems.insert(nums[i]);
        }

        int answer = 1;
        int count = 1;
        int elem;
        for (int i=0; i<n; i++) {
            // first element in a sequence
            if (elems.find(nums[i]-1) == elems.end()) {
                count = 1;
                elem = nums[i] + 1;
                while (elems.find(elem) != elems.end()) {
                    count ++;
                    elem++;
                }
                if (count > answer) {
                    answer = count;
                }
            }
        }
        return answer;
    }
};