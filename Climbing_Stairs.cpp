#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        std::vector<int> tab(n, 1);
        tab[1] = 2;
        for (int i=2; i<n; i++) {
            tab[i] = tab[i-1] + tab[i-2];
        }

        return tab[n-1];
    }
};