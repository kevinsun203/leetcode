#include "vector"
#include "queue"
using namespace std;


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // not visited = -1, any other value represents distance from
        // closest 0
        vector<vector<int>> answer(m, vector<int>(n, -1));

        queue<pair<int, int>> q;

        // Fill the queue with indices of 0 elements and mark them as visited i.e. distance = 0
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i,j});
                    answer[i][j] = 0;
                }
            }
        }

        //BFS. Note that the only unvisited nodes will be the elements with 1
        while (!q.empty()) {
            // indices of parent vertice
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            // check whether adjacent vertices exist, add them to queue if not visited and update answer
            if (i+1 < m && answer[i+1][j] == -1) {
                q.push({i+1,j});
                answer[i+1][j] = answer[i][j] + 1;
            } 
            if (i-1 > -1 && answer[i-1][j] == -1) {
                q.push({i-1, j});
                answer[i-1][j] = answer[i][j] + 1;
            }
            if (j+1 < n && answer[i][j+1] == -1) {
                q.push({i, j+1});
                answer[i][j+1] = answer[i][j] + 1;
            } 
            if (j-1 > -1 && answer[i][j-1] == -1) {
                q.push({i, j-1});
                answer[i][j-1] = answer[i][j] + 1;
            }

        }
        return answer;
    }


};