#include "algorithm"
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int result=0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;   
        }
        helper(root, 0);
        return result;
    }

    int helper(TreeNode* root, int count) {
        if (root == nullptr) {
            return count-1;
        }

        // Get max depths on either side 
        int leftDepth = helper(root->left, count+1);
        int rightDepth = helper(root->right, count+1);

        // Get the current longest path and update the variable if necessary
        int currLongest = (leftDepth - count) + (rightDepth - count);
        result = currLongest > result ? currLongest : result;

        // Return max depth 
        return max(leftDepth, rightDepth);

    }
};