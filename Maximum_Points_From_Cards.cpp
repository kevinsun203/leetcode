#include "vector";
#include "algorithm";
using namespace std;

// sliding window to find largest removable subarray
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        if (cardPoints.size() == 0 || k == 0) {
            return 0;
        }
        int arraySize = cardPoints.size() - k;
        int answer=0;
        int tempSum = 0;
        int minSum;
        for (int i=0; i<cardPoints.size(); i++) {
            answer += cardPoints[i];
        }
        for (int i=0; i<arraySize; i++) {
            tempSum += cardPoints[i];
        }
        minSum = tempSum;


        for (int i=1; i<cardPoints.size()-arraySize+1; i++) {
            tempSum -= cardPoints[i-1];
            tempSum += cardPoints[i+arraySize-1];
            minSum = min(tempSum, minSum);
        }
        return answer - minSum;
    }
};