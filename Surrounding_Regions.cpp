#include <vector>
#include <queue>

class Solution {
private:
    int numCols;
    int numRows;
public:
    void solve(std::vector<std::vector<char>>& board) {
        numCols = board[0].size();
        numRows = board.size();

        // We run bfs exclusively through border cells
        for (int row=0; row<numRows; row++) {
            for (int col=0; col<numCols; col++) {
                if ((row == 0 || row == numRows-1 || col == 0 || col == numCols-1) && board[row][col] == 'O') {
                    bfs(board, row, col);
                }
            }
        }

        // Iterate through the board and at every instance where there is a '1', we make it an 'O'.
        // Wherever there is an 'O', we make it an 'X'
        for (int row=0; row<numRows; row++) {
            for (int col=0; col<numCols; col++) {
                if (board[row][col] == 'O') {
                    board[row][col] = 'X';
                } 
                if (board[row][col] == 'E') {
                    board[row][col] = 'O';
                }
            }
        }

        return;
    }

    void bfs(std::vector<std::vector<char>>& board, int row, int col) {
        std::queue<std::pair<int, int>> q;
        q.push({row, col});
        board[row][col] = 'E';

        // bfs through the island and mark them all as 1's (cannot be flipped and visited)
        while (!q.empty()) {
            std::pair<int, int> curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;
            
            // Left cell
            if (x > 0 && board[x-1][y] == 'O') {
                board[x-1][y] = 'E';
                q.push({x-1, y});
            }
                                    
            // Insert right cell
            if (x < numRows-1 && board[x+1][y] == 'O') {
                board[x+1][y] = 'E';
                q.push({x+1, y});
            }

            // insert top cell
            if (y > 0 && board[x][y-1] == 'O') {
                board[x][y-1] = 'E';
                q.push({x, y-1});
            }

            //insert bottom cell
            if (y < numCols-1 && board[x][y+1] == 'O') {
                board[x][y+1] = 'E';
                q.push({x,y+1});
            }
        }
    }
};