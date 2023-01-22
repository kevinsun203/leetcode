// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root, p, q);
    }

    TreeNode* helper(TreeNode* curr, TreeNode* p, TreeNode* q) {
        if (p->val > curr->val && q->val < curr->val) {
            return curr;
        } else if (p->val < curr->val && q->val > curr->val) {
            return curr;
        } else if (p->val == curr->val){
            return p;
        } else if (q->val == curr->val) {
            return q;
        } else if (p->val < curr->val) {
            return helper(curr->left, p, q);
        } else {
            return helper(curr->right, p, q);
        }
    }
};