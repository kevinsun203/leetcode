#include "vector";
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector <int> answer;
        answer.push_back(1);
        int product = 1;

        //prefix
        for (int i=0; i<nums.size()-1; i++) {
            product *= nums[i];
            answer.push_back(product);
        }

        product = 1;
        //suffix
        for (int j=nums.size()-1; j>=1; j--) {
            product *= nums[j];
            answer[j-1] *= product;
        }

        return answer;



    }
};