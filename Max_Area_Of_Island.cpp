#include <vector>
#include <queue>

// same sol'n as number of islands
class Solution {
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        std::vector<std::vector<int>> visited(grid.size(), std::vector<int>(grid[0].size(), -1));

        int answer = 0;
        for (int row=0; row<grid.size(); row++) {
            for (int col=0; col<grid[0].size(); col++) {
                if (visited[row][col] == -1 && grid[row][col] == 1) {
                    bfs(grid, visited, row, col, answer);
                }
            }
        }
        return answer;
    }

    void bfs(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& visited, int row, int col, int& answer) {
        std::queue<std::pair<int, int>> q;
        q.push({row, col});
        int numLands = 0;
        visited[row][col] = 1;

        while (!q.empty()) {
            std::pair<int, int> coord = q.front();
            row = coord.first;
            col = coord.second;
            q.pop();
            numLands++;

            // insert left cell
            if (row > 0 && visited[row-1][col] == -1 && grid[row-1][col] == 1) {
                visited[row-1][col] = 1;
                q.push({row-1,col});
            }

            // insert right cell
            if (row < grid.size()-1 && visited[row+1][col] == -1 && grid[row+1][col] == 1) {
                visited[row+1][col] = 1;
                q.push({row+1,col});
            }

            // insert bottom cell
            if (col > 0 && visited[row][col-1] == -1 && grid[row][col-1] == 1) {
                visited[row][col-1] = 1;
                q.push({row,col-1});
            }
            // insert top cell
            if (col < grid[0].size()-1 && visited[row][col+1] == -1 && grid[row][col+1] == 1) {
                visited[row][col+1] = 1;
                q.push({row,col+1});
            }
        }
        answer = answer > numLands ? answer : numLands;
        return;
    }
};