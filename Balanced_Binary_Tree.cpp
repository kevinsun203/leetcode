#include "algorithm"
using namespace std;

//Definition for a binary tree node.
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
    bool answer;
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        answer = true;
        helper(root, 1);
        return answer;
    }

    int helper(TreeNode* node, int count) {
        if (node == nullptr) {
            return count - 1;
        }
        int left = helper(node->left, count+1);
        int right = helper(node->right, count+1);
        if (abs(left-right) > 1 && answer) {
            answer = false;
        }
        return max(left, right);        
    }
};