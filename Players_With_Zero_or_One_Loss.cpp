#include "vector";
#include "algorithm";
#include "map";
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> losses;
        for (int i=0; i<matches.size(); i++) {
            if (losses.find(matches[i][1]) == losses.end()) {
                losses.insert({matches[i][1], 1});
            } else {
                losses[matches[i][1]]++;
            }

            if (losses.find(matches[i][0]) == losses.end()) {
                losses.insert({matches[i][0], 0});
            } 
        }

        vector <int> noLosses;
        vector <int> oneLoss;
        for (auto i=losses.begin(); i != losses.end(); i++) {
            if (i->second == 0) {
                noLosses.push_back(i->first);
            } else if (i->second == 1) {
                oneLoss.push_back(i->first);
            }
        }
        vector <vector<int>> answer;
        sort(noLosses.begin(), noLosses.end());
        sort(oneLoss.begin(), oneLoss.end());
        answer.push_back(noLosses);
        answer.push_back(oneLoss);
        return answer;
        
    }
};