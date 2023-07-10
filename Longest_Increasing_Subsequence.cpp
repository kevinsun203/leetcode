#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        std::vector<int> tab(n, 1);
        int answer = 1;
        for (int i=1; i<n; i++) {
            int local_max = tab[i];
            for (int j=0; j<i; j++) {
                if (nums[i] > nums[j]) {
                    local_max = max(local_max, 1+tab[j]);
                }
            }
            tab[i] = local_max;
            answer = max(local_max, answer);
        }

        return answer;
    }
};