#include "string"
#include "vector"
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int wSize = s1.size();
        if (wSize > s2.size()) {
            return false;
        }

        vector<int> oFreq(26,0), pFreq(26,0);
        // First window
        for (int i=0; i<wSize; i++) {
            oFreq[s2[i]-'a']++;
            pFreq[s1[i]-'a']++;
        } 
        if (oFreq == pFreq) {
            return true;
        }

        for (int i=1; i<s2.size()-wSize+1; i++) {
            oFreq[s2[i-1]-'a']--;
            oFreq[s2[i+wSize-1]-'a']++;
            if (oFreq == pFreq) {
                return true;
            }
        }
        return false;
    }
};