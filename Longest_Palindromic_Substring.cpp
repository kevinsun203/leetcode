#include "string";
using namespace std;

// O(n^2) - expand from centre
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 1) {
            return s;
        }
        string answer;
        int max = 0;
        for (int i=0; i<n; i++) {
            auto first = expandFromMiddle(s, i, i);
            auto second = expandFromMiddle(s, i, i+1);
            if (first.second - first.first + 1 > max) {
                max = first.second - first.first + 1;
                answer = s.substr(first.first, first.second-first.first+1);
            }
            if (second.second - second.first + 1 > max) {
                max = second.second - second.first + 1;
                answer = s.substr(second.first, second.second-second.first+1);
            }
        }
        return answer;
    }

    pair<int, int> expandFromMiddle(string s, int centerLeft, int centerRight) {
        int n = s.length();
        while (centerLeft >= 0 && centerRight <= n-1 && s[centerLeft] == s[centerRight]) {
            centerLeft--;
            centerRight++;
        }
        if (centerRight-1 == centerLeft) {
            return {centerLeft, centerLeft};
        } else {
            return {centerLeft+1, centerRight-1};
        }
    }
};