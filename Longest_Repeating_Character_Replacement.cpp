#include "unordered_map"
#include "string"
using namespace std;


class Solution {
public:
    int characterReplacement(string s, int k) {
        int answer = 0;
        int n = s.length();
        unordered_map <char, int> freq;
        int j=0;
        for (int i=0; i<n; i++) {
            if (freq.find(s[i]) == freq.end()) {
                freq.insert({s[i], 1});
            } else {
                freq[s[i]]++;
            }
            //find new valid window
            while (i-j+1-findMax(freq) > k) {
                freq[s[j]]--;
                j++;
            }

            if (i-j+1 > answer) {
                answer = i-j+1;
            }
        }
        return answer;
    }

    int findMax(unordered_map<char, int>& freq) {
        int max = INT_MIN;
        for (auto idx=freq.begin(); idx!=freq.end(); idx++) {
            if (idx->second > max) {
                max = idx->second;
            }
        }  
        return max;
    }
};