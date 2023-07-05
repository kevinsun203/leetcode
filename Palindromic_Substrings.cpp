#include <string>

class Solution {
public:
    int countSubstrings(std::string s) {
        int count = 0;
        int n = s.size();

        for (int i=0; i<n; i++) {
            fromCenterOut(s, i, i, count);
            fromCenterOut(s, i, i+1, count);
        }

        return count;
    }

    void fromCenterOut(std::string s, int centerLeft, int centerRight, int& count) {
        int len = s.size();
    
        while (centerLeft >= 0 && centerRight <= len-1) {
            if (s[centerLeft] == s[centerRight]) {
                count++;
            } else {
                break;
            }
            centerLeft--;
            centerRight++;
        }
        return;
    }
};