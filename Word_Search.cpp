#include <vector>
#include <string>

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        for (int row=0; row<board.size(); row++) {
            for (int col=0; col<board[0].size(); col++) {
                if (helper(board, word, row, col, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool helper(std::vector<std::vector<char>>& board, std::string word, int row, int col, int index) {

        // word found
        if (index == word.size()) {
            return true;
        }

        if (row >= board.size() || row < 0 || col >= board[0].size() || col < 0) {
            return false;
        }

        if (board[row][col] == '-1') {
            return false;
        }

        if (board[row][col] != word[index]) {
            return false;
        }

        board[row][col] = '-1'; // mark the current cell as visited

        // Traverse the four directions
        if (helper(board, word, row-1, col, index+1)) {
            return true;
        }

        if (helper(board, word, row+1,col, index+1)) {
            return true;
        }

        if (helper(board, word, row, col-1, index+1)) {
            return true;
        }

        if (helper(board, word, row,col+1, index+1)) {
            return true;
        }

        board[row][col] = word[index]; // re-mark cell as non-visited 
        return false;
    }
};