#include "string";
using namespace std;

// bad brute force O(n^3) method lmao 
class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.length();
        string answer = "";
        string substring;
        bool isPalindrome = true;
        if (s.length() == 1) {
            return s;
        }
        for (int i=0; i<length; i++) {
            for (int j=i; j<length; j++) {
                isPalindrome = true;
                for (int c=0; c<(j-i+1)/2; c++) {
                    if (s[i+c] != s[j-c]){
                        isPalindrome = false;
                        break;
                    }
                }
                if(isPalindrome && j - i +1 > answer.length()) {
                    answer = s.substr(i,j-i+1);
                }
            }
        }
        return answer;
    }
};