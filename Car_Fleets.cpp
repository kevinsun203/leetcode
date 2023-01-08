#include "stack"
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<pair<int,double>> stck;
        vector<pair<int, double>> cars;
        int n = position.size();
        for (int i=0; i<n; i++) {
            cars.push_back({position[i], (double)(target-position[i])/speed[i]});
        }

        sort(cars.begin(), cars.end(), [](auto x, auto y){return x.first < y.first;});

        for (int i=n-1; i>=0; i--) {
            if (stck.empty() || cars[i].second>stck.top().second) {
                stck.push(cars[i]);
            } 
        }
        return stck.size();
    }
};