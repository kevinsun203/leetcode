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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) {
            return false;
        }

        if (sameTree(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool sameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q != nullptr) {
            return false;
        } else if (p != nullptr && q == nullptr) {
            return false;
        } else if (p == nullptr && q == nullptr) {
            return true;
        } else if (p->val != q->val) {
            return false;
        }

        return sameTree(p->left, q->left) && sameTree(p->right, q->right);
    }
};