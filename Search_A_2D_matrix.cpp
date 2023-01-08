#include "vector"
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Find row of matrix
        int row = findRow(matrix, 0, matrix.size()-1, target);
        if (row < 0 || row == matrix.size()) {
            return false;
        }
        //Find number inside row of matrix
        return binarySearch(matrix[row], 0, matrix[row].size()-1, target);

    }

    int findRow(vector<vector<int>>& matrix, int begin, int end, int target) {
        if (begin > end) {
            return -1;
        }
        int median = (begin+end)/2;

        if (matrix[median][0] <= target && (median == end || matrix[median+1][0] > target)) {
            return median;
        } else if (target > matrix[median][0]) {
            return findRow(matrix, median+1, end, target);
        } else {
            return findRow(matrix, begin, median-1, target);
        }
    }

    bool binarySearch(vector<int> row, int begin, int end, int target) {
        if (begin > end) {
            return false;
        }

        int median = (begin+end)/2;
        if (row[median] == target) {
            return true;
        } else if (row[median] > target){
            return binarySearch(row, begin, median-1, target);
        } else {
            return binarySearch(row, median+1, end, target);
        }
    }
};