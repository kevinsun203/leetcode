#include "vector"
#include "iostream"
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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        vector<int> nextPair;
        if (root == NULL) {
            return answer;
        }
        traverse(root, 0, answer);
        return answer;

    }

    void traverse(TreeNode* node, int level, vector<vector<int>>& answer) {
        if (node == NULL) {
            return;
        }
        if (answer.size() == level) {
            answer.push_back({node->val});
        } else {
            answer[level].push_back(node->val);
        }
        traverse(node->left, level+1, answer);
        traverse(node->right, level+1, answer);
    }
};