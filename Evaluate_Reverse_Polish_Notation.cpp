#include "vector"
#include "string"
#include "stack"
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int n = tokens.size();
        for (int i=0; i<n; i++) {
            if (tokens[i] != "*" && tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "/") {
                nums.push(stoi(tokens[i]));
            } else {
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();

                if (tokens[i] == "*") {
                    nums.push(num1*num2);
                } else if (tokens[i] == "+") {
                    nums.push(num1+num2);
                } else if (tokens[i] == "-") {
                    nums.push(num2-num1);
                } else {
                    nums.push(num2/num1);
                }
            }
        }
        return nums.top();
    }
};