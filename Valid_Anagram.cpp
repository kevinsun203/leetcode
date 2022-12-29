#include "string"
#include "vector"
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freqO(26, 0);
        vector<int> freqA(26, 0);

        for (int i=0; i<t.length(); i++) {
            freqO[t[i]-'a']++;
        }

        for (int i=0; i<s.length(); i++) {
            freqA[s[i]-'a']++;
        }

        if (freqO == freqA) {
            return true;
        } else {
            return false;
        }

    }
};