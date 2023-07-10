using namespace std;
#include <vector>
#include <queue>

struct islandCell {
    int row;
    int col;
    int ocean; // 0 for pacific, 1 for atlantic
    islandCell(int x, int y, int water) : row(x), col(y), ocean(water) {}
};

class Solution {
private:
    int numRows;
    int numCols;
    bool valid(int i, int j) {
        return (0 <= i) && (i < numRows) && (0 <= j) && (j < numCols);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        numRows = heights.size();
        numCols = heights[0].size();
        std::vector<std::vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // Keep track of what oceans have visited each cell - 0 for pacific and 1 for atlantic
        vector<vector<vector<int>>> visited(numRows, vector<vector<int>>(numCols, vector<int>(2, 0)));
        
        std::queue<islandCell*> q;

        // Push all edges onto queue
        for (int i=0; i<numRows; i++) {
            q.push(new islandCell(i, 0, 0)); // pacific 
            q.push(new islandCell(i, numCols-1, 1)); // atlantic
            visited[i][0][0] = 1;
            visited[i][numCols-1][1] = 1;
        }

        // Push all edges onto queue
        for (int i=0; i<numCols; i++) {
            q.push(new islandCell(0, i, 0)); // pacific
            q.push(new islandCell(numRows-1, i, 1)); // atlantic

            visited[0][i][0] = 1;
            visited[numRows-1][i][1] = 1;
        }   
        std::vector<std::vector<int>> answer;

        // bfs
        while (!q.empty()) {
            islandCell* curr = q.front();
            q.pop();

            int row = curr->row;
            int col = curr->col;
            int oceanOfOrigin = curr->ocean;

            // Insert adjacent cells into the queue
            for (auto dir: dirs) {
                int i = row + dir[0];
                int j = col + dir[1];
                if (valid(i, j) && (heights[row][col] <= heights[i][j]) && !visited[i][j][oceanOfOrigin]) {
                    visited[i][j][oceanOfOrigin] = 1;
                    q.push(new islandCell(i, j, oceanOfOrigin));
                }
            }

        }

        // check if we get the part can flow to two side.
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (visited[i][j][0] && visited[i][j][1]) {
                    answer.push_back({i, j});
                }
            }
        }
        return answer;
    }
};