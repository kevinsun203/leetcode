#include <string>
#include <vector>
#include <algorithm>

// sort by comparing which order of strings gives the largest integer value
class Solution {
public:
    struct sortByDigit {
        bool operator()(std::string& a, std::string& b) {
            return a+b > b+a;
        }
    };

    std::string largestNumber(std::vector<int>& nums) {
        std::string answer = "";
        int len = nums.size();
        std::vector<std::string> sortedStrings;
        long totalSum = 0;
        for (int i=0; i<len; i++) {
            totalSum += nums[i];
            sortedStrings.push_back(std::to_string(nums[i]));
        }        

        if (totalSum == 0) {
            return "0";
        }
        sort(sortedStrings.begin(), sortedStrings.end(), sortByDigit());

        for (int i=0; i<len; i++) {
            answer += sortedStrings[i];
        }
        return answer;
    }
};