#include <vector>
#include <string>

class Solution {
private:
    std::vector<std::vector<std::string>> answer;
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::string> curr;
        helper(s, curr, 0);
        return answer;
    }

    void helper(std::string& s, std::vector<std::string>& curr, int index) {
        if (index == s.size()) {
            answer.push_back(curr);
            return;
        }

        for (int i=index; i<s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                curr.push_back(s.substr(index, i-index+1));
                helper(s, curr, i+1);
                curr.pop_back();
            }
        }
     }

    bool isPalindrome(std::string& s, int begin, int end) {
        if (end-begin == 0) {
            return true;
        }

        while (begin <= end) {
            if (s[begin] != s[end]) {
                return false;
            }
            begin++;
            end--;
        }
        return true;
    } 
};