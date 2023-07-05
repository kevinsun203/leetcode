#include <vector>
#include <queue>

class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        int timeStep = 0;   
        std::queue<std::pair<int, int>> q;
        
        int numFresh = 0;
        int numRotten = 0;

        int numRows = grid.size();
        int numCols = grid[0].size();
        // Insert all rotten oranges into the queue
        for (int row=0; row<numRows; row++) {
            for (int col=0; col<numCols; col++) {
                if (grid[row][col] == 2) {
                    numRotten++;
                    q.push({row, col});
                    grid[row][col] = -1;
                } else if (grid[row][col] == 1) {
                    numFresh++;
                }
            }
        }
        q.push({-1, -1}); // mark the decay of a minute

        int numContaminated = 0;
        while (!q.empty()) {
            std::pair<int, int> curr = q.front();
            q.pop();

            if (curr.first == -1) {
                timeStep++;
                if (!q.empty()) {
                    q.push({-1,-1});
                }
                continue;
            }

            // Insert neighbours
            int x = curr.first;
            int y = curr.second;
            if (x >= 1 && grid[x-1][y] == 1) {
                q.push({x-1, y});
                grid[x-1][y] = -1;
                numContaminated++;
            }

            if (x < numRows-1 && grid[x+1][y] == 1) {
                q.push({x+1,y});
                grid[x+1][y] = -1;
                numContaminated++;
            }

            if (y >= 1 && grid[x][y-1] == 1) {
                q.push({x,y-1});
                grid[x][y-1] = -1;
                numContaminated++;
            }

            if (y < numCols-1 && grid[x][y+1] == 1) {
                q.push({x, y+1});
                grid[x][y+1] = -1;
                numContaminated++;
            }
        }
        if (numFresh != numContaminated) {
            return -1;
        }
        return timeStep-1;
    }
};