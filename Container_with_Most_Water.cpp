#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int length = height.size();
        int tempArea;
        int answer = -1;
        int left = 0;
        int right = length - 1;
        while (right > left) {
            tempArea = (right - left) * min(height[right], height[left]);
            if (tempArea > answer) {
                answer = tempArea;
            }
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }

        }
        return answer;
    }
};