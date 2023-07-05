#include <bits/stdc++.h>
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
    int goodNodes(TreeNode* root) {
        int max = INT_MIN;
        int answer = 0;
        helper(root, max, answer);
        return answer;
    }

    // DFS - pre order traversal
    void helper(TreeNode* root, int max, int& answer) {
        if (root == nullptr) {
            return;
        }

        if (root->val >= max) {
            max = root->val;
            answer++;
        }
        helper(root->left, max, answer);
        helper(root->right, max, answer);
    }
};