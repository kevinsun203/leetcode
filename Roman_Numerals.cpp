#include "string";
#include "stack";
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string answer;
        stack <int> repr;


        
        // stack of digits
        while (num > 0) {
            int temp = num % 10;
            repr.push(temp);
            num /= 10;
        }
        int place;
        int digit;
        string romanChar;
        while (!repr.empty()) {
            place = repr.size();
            digit = repr.top();
            string romanChar;
            if (digit == 4) {
                switch (place) {
                    case 3: romanChar = "CD";
                            break;
                    case 2: romanChar = "XL";
                            break;
                    case 1: romanChar = "IV";
                            break;
                }
            } else if (digit == 9) {
                switch (place) {
                    case 3: romanChar = "CM";
                            break;
                    case 2: romanChar = "XC";
                            break;
                    case 1: romanChar = "IX";
                            break;
                }
            } else {
                if (place == 4) {
                    for (int i=0; i<digit; i++) {
                        romanChar += "M";
                    }
                    
                } else if (place == 3) {
                    while (digit > 0) {
                        if (digit >= 5) {
                            romanChar += "D";
                            digit -= 5;
                        } else if (digit < 5) {
                            romanChar += "C";
                            digit -= 1;
                        }
                    }
                } else if (place == 2) {
                    while (digit > 0) {
                        if (digit >= 5) {
                            romanChar += "L";
                            digit -= 5;
                        } else if (digit < 5) {
                            romanChar += "X";
                            digit -= 1;
                        }
                    }
                } else if (place == 1) {
                    while (digit > 0) {
                        if (digit >= 5) {
                            romanChar += "V";
                            digit -= 5;
                        } else if (digit < 5) {
                            romanChar += "I";
                            digit -= 1;
                        }
                    }
                }
            }
            answer += romanChar;
            repr.pop();

        }
        return answer;
    }
};