#include "unordered_set";
#include "vector";
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> cms(9);
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> blks(9);

        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                char c = board[i][j];
                if (c != '.') {
                    int blkIdx = (i/3)*3+j/3;
                    if (cms[j].find(c)!=cms[j].end()) {
                        return false;
                    } else {
                        cms[j].insert(c);
                    }
                    if (rows[i].find(c)!=rows[j].end()) {
                        return false;
                    } else {
                        rows[i].insert(c);
                    }
                    if (blks[blkIdx].find(c)!=blks[blkIdx].end()) {
                        return false;
                    } else {
                        blks[blkIdx].insert(c);
                    }
                }
            }
        }
        return true;
    }
    
};