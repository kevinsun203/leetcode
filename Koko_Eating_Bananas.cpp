#include "vector"
#include "algorithm"
#include "cmath"
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxSpeed = 0;
        int answer = INT_MAX;
        for (int i=0; i<piles.size(); i++) {
            maxSpeed = max(piles[i], maxSpeed);
        }

        //binary search for the optimal banana eating speed
        int left = 1;
        int right = maxSpeed;
        while (left <= right) {
            int speed = (left+right)/2;
            double hours = 0;
            for (int i=0; i<piles.size(); i++) {
                hours += ceil((double)piles[i]/speed);
            }
            if (hours <= h) {
                if (speed < answer) {
                    answer = speed;
                }
                right = speed-1;
            } else {
                left = speed+1;
            }
        }
        return answer;
    }
};