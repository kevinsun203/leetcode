#include <vector>
#include <queue>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int numCols = grid.size();
        int numRows = grid[0].size();

        // Matrix to keep track of which cells have been visited. -1 indicates that it hasn't
        // been visited and 1 indicates that it has been visited
        std::vector<std::vector<int>> visited(numCols, std::vector<int>(numRows, -1));

        int result = 0;

        // BFS on each island
        for (int i=0; i<numCols; i++) {
            for (int j=0; j<numRows; j++) {
                if (grid[i][j] == '1' && visited[i][j] == -1) {
                    result++;
                    bfs(grid, i, j, visited);
                }
            }
        }
        return result;
    }

    // Bfs starting from a "1" and expanding across the entire island (all reachable "1"'s that don't cross a "0")
    void bfs(std::vector<std::vector<char>>& grid, int x, int y, std::vector<std::vector<int>>& visited) {
        int numCols = grid.size();
        int numRows = grid[0].size();

        std::queue<std::pair<int, int>> q;
        q.push({x,y});    

        while (!q.empty()) {
            std::pair<int, int> coord = q.front();
            q.pop();

            int xC = coord.first;
            int yC = coord.second;
            // check left cell
            if (xC >= 1 && visited[xC-1][yC] == -1 && grid[xC-1][yC] == '1') {
                q.push({xC-1,yC});
                visited[xC-1][yC] = 1;
            }

            // check right cell
            if (xC < numCols-1 && visited[xC+1][yC] == -1 && grid[xC+1][yC] == '1') {
                q.push({xC+1,yC});
                visited[xC+1][yC] = 1;
            }

            // check top cell
            if (yC >= 1 && visited[xC][yC-1]== -1 && grid[xC][yC-1] == '1') {
                q.push({xC, yC-1});
                visited[xC][yC-1] = 1;
            }

            // check bottom cell
            if (yC < numRows-1 && visited[xC][yC+1] == -1 && grid[xC][yC+1] == '1') {
                q.push({xC,yC+1});
                visited[xC][yC+1] = 1;
            }
        }
    }
};