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
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return traverse(root, 1);
    }

    int traverse(TreeNode* root, int count) {
        if (root->left == nullptr && root->right == nullptr) {
            return count;
        }
        int left = 0;
        int right = 0;
        if (root->left != nullptr) {
            left = traverse(root->left, count+1);
        }

        if (root->right != nullptr) {
            right = traverse(root->right, count+1);
        }
        return max(left, right);

    }   
};