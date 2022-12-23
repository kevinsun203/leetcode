#include "vector";
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;
        int white = 0;
        int blue = 0;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            if (nums[i] == 1) {
                white++;
            } else if (nums[i] == 0) {
                red++;
            } else {
                blue++;
            }
        }

        for (int i=0; i<n; i++) {
            if (red != 0) {
                nums[i] = 0;
                red--;
            } else if (white != 0) {
                nums[i] = 1;
                white--;
            } else {
                nums[i] = 2;
                blue--;
            }
        }
        return;
    }
};