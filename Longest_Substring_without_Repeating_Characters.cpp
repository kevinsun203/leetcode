#include "iostream";
#include "vector";
#include "string";
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int answer = 0;
        int totalLength = s.length();
        if (totalLength == 0) {
            return 0;
        }
        if (totalLength == 1) {
            return 1;
        }

        
        for (int i=0; i<totalLength; i++) {
            // reset visited vector each window slide
            vector<bool> visited(256, false);
            for (int j=i; j<totalLength; j++) {
                if (visited[s[j]] == true) {
                    break;
                } else {
                    answer = max(answer, j - i + 1);
                    visited[s[j]] = true;
                }
            }
        }
        return answer;
    }
};