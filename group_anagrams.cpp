#include "vector"
#include "map"
#include "string"
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // map of frequency arrays with their respective strings
        map<vector<int>, vector<string>> elems;

        for (int i=0; i<strs.size(); i++) {
            vector<int> freqTemp(26,0);
            for(int j=0; j<strs[i].size(); j++) {
                freqTemp[strs[i][j]-'a']++;
            }
            if (elems.find(freqTemp) == elems.end()) {
                elems.insert({freqTemp, {strs[i]}});
            } else {
                elems[freqTemp].push_back(strs[i]);
            }
        }
        vector <vector<string>> answer;
        for (auto idx=elems.begin(); idx != elems.end(); idx++) {
            answer.push_back(idx->second);
        }
        return answer;
    }
};