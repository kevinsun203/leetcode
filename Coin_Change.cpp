#include <vector>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> tab(amount+1, amount+2);
        int n = coins.size();
        tab[0] = 0; // 0 coins to create 0 dollars

        for (int i=1; i<=amount; i++) { // Loop through all the amounts up until the target
            for (int j=0; j<n; j++) { // Loop through all the coins
                if (i-coins[j] >= 0) {
                    tab[i] = std::min(tab[i], 1+tab[i-coins[j]]);
                }
            }
        }

        if (tab[amount] == amount+2) {
            return -1;
        } else {
            return tab[amount];
        }
    }
};