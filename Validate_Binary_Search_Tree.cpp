
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
    bool isValidBST(TreeNode* root) {  
        long max = LONG_MAX;
        long min = LONG_MIN;
        return helper(root, min, max);
    }

    bool helper(TreeNode* curr, long minimum, long maximum) {
        if (curr == NULL) {
            return true;
        }

        // verify current node
        if (curr->val < maximum && curr->val > minimum) {

            // Check subtrees with new bounding conditions
            return helper(curr->left, minimum, long(curr->val)) && helper(curr->right, long(curr->val), maximum);
        }

        return false;
    }

};