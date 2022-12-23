#include "cmath";
#include "vector";
#include "algorithm";
using namespace std;

class Solution {

    // functor
    struct sortGreater {
        bool operator()(vector<int>& a, vector<int>& b) {
            int a_d = a[0]*a[0] + a[1] * a[1];
            int b_d = b[0]*b[0] + b[1] * b[1];
            return a_d > b_d;
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> answer;
        make_heap(points.begin(), points.end(), sortGreater());


        for (int i=0; i<k; i++) {
            vector<int> temp = points.front();
            pop_heap(points.begin(), points.end(), sortGreater());

            // since pop_heap moves the greatest element to the back of the vector
            points.pop_back();
            answer.push_back(temp);
        }
        return answer;
    }
};