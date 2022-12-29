
//  * Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if (root->val == p->val || root->val == q->val) {
             return root;
         }
         bool pLoc = foundNode(root->left, p);
         bool qLoc = foundNode(root->right, q);
         if (pLoc == qLoc) {
             return root;
         } else if (pLoc) {
             return lowestCommonAncestor(root->left, p, q);
         } else {
             return lowestCommonAncestor(root->right, p, q);
         }
    }

    bool foundNode(TreeNode* root, TreeNode* toFind) {
        if(root == nullptr) {
            return false;
        } else if (root->val == toFind->val) {
            return true;
        }

        return foundNode(root->left, toFind) || foundNode(root->right, toFind);
    }
};

// TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//     if (!root || root == p || root == q) return root;
//     TreeNode* left = lowestCommonAncestor(root->left, p, q);
//     TreeNode* right = lowestCommonAncestor(root->right, p, q);
//     if(left == null && right == null) return null; 
//     if(left != null && right != null) return root;  
//     return left == null ? right : left;
// }