#include <vector>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        return build(preorder, inorder, index, 0, preorder.size()-1);
        
    }

    // index: subtree with preorder[index] as root
    // begin: beginning of inorder array index where the current subtree is located
    // end: ending of inorder array index current subtree is located
    TreeNode* build(std::vector<int>& preorder, std::vector<int>& inorder, int& index, int begin, int end) {
        if (begin > end) {
            return nullptr;
        }

        // Create new root
        TreeNode* root = new TreeNode(preorder[index]);
        // Identify the pivot point of the current subtree in the inorder array
        int splitIdx=0;
        for (int i=0; i<preorder.size(); i++) {
            if (preorder[index] == inorder[i]) {
                splitIdx = i;
                break;
            }
        }
        index++;
        root->left = build(preorder, inorder, index, begin, splitIdx-1);
        root->right = build(preorder, inorder, index, splitIdx+1, end);

        return root;
    }
};