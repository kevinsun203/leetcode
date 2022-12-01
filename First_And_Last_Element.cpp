#include "string"
#include "map"
#include "stack"
#include "vector"
#include "iostream"
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> answer = {-1, -1};
        if (nums.size() < 1) {
            return answer;
        } else if (nums.size() == 1 && target == nums[0]) {
            answer = {0,0};
            return answer;
        }
        int position = binarySearch(nums, 0, nums.size()-1, target);
        if (position != -1) {
        
          int position2 = position+1;
          while (position2 < nums.size() && nums[position2] == target) {
            cout << "here" << endl;
              position2++;
          }
          position2--;


          answer.pop_back();
          answer.pop_back();
          answer.push_back(position);
          answer.push_back(position2);
        }
        return answer;
        
    }

    int binarySearch(vector<int>& nums, int begin, int end, int target) {  
        if (begin > end) {
            return -1;
        }  
        int medianIndex = (begin + end)/ 2;
        if (target == nums[medianIndex]) {
            medianIndex--;
            while (medianIndex >= 0 && nums[medianIndex] == target) {
                medianIndex--;
            }
            return medianIndex+1;
        } else if (target > nums[medianIndex]) {
            return binarySearch(nums, medianIndex + 1, end, target);
        } else {
            return binarySearch(nums, begin, medianIndex - 1, target);
        } 
    }
};
