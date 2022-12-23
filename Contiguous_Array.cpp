#include "vector"
#include "map"
#include "Cmath"
#include "algorithm"
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> count;
        int n = nums.size();
        int sum = 0;
        if (n == 1) {
            return 0;
        }
        int answer = 0;
        int tempAnswer;
        for (int i=0; i<n; i++) {
            if (nums[i] == 1) {
                sum += 1;
            } else {
                sum += -1;
            }
            if (count.find(sum) != count.end()) {
                tempAnswer = i - (count.find(sum)->second);
                answer = max(tempAnswer, answer); 
            } else if (sum == 0) {
                tempAnswer = i+1;
                answer = max(tempAnswer, answer);
            }else {
                count.insert({sum, i});
            }
        }
        return answer;
    }
};