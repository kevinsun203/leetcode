#include "unordered_map"
#include "string"
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        int answer = 0;
        int n = s.length();
        for (int i=0; i<n; i++) {
            if (freq.find(s[i]) == freq.end()) {
                freq[s[i]] = 1;
            } else {
                freq[s[i]]++;
            }
        }
        bool oddExists = false;
        for (auto i=freq.begin(); i != freq.end(); i++) {
            if (i->second % 2 == 0) {
                answer += i->second;
            } else {
                answer += i->second-1;
                oddExists = true;
            }
        }

        answer = oddExists ? answer + 1 : answer;
        return answer;
    }
};