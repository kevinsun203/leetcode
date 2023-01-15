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
    int result;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;   
        }
        result = 0;
        helper(root, 1);
        return result;
    }

    int helper(TreeNode* root, int count) {
        if (root == nullptr) {
            return count-1;
        }
        int right = 0;
        int left = 0;
        left = helper(root->left, count+1);
        right = helper(root->right, count+1);
        
        result = max((left-count)+(right-count), result);
        return max(left, right);
    }
};