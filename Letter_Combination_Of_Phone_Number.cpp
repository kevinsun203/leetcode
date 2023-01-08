#include "unordered_map"
#include "string"
#include "vector"
using namespace std;
// i hate recursion
class Solution {
private:
    unordered_map<char, string> nums;
    vector<string> answer;

public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }
        nums['2'] = "abc";
        nums['3'] = "def";
        nums['4'] = "ghi";
        nums['5'] = "jkl";
        nums['6'] = "mno";
        nums['7'] = "pqrs";
        nums['8'] = "tuv";
        nums['9'] = "wxyz";
        helper(digits, 0,"");
        return answer;

    }

    void helper(string digits, int place,  string curr) {
        if (place == digits.length()) {
            answer.push_back(curr);
            return;
        }
        int n = nums[digits[place]].length();     
        for (int i=0; i<n; i++) {
            curr.push_back(nums[digits[place]][i]);
            helper(digits, place+1, curr);
            curr.pop_back();
        }
        return;
    }
};