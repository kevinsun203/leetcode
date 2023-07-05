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
    int answer;
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        in_order(root, count, k);
        return answer;
        
    }

    void in_order(TreeNode* curr, int& count, int k) {
        if (curr == nullptr) {
            return;
        }

        in_order(curr->left, count, k);

        count++;
        if (count == k) {
            answer = curr->val;
            return;
        }

        in_order(curr->right, count, k);
    }
};