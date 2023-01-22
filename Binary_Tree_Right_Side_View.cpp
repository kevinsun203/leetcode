#include "vector"
#include "queue"
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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> answer;
        queue <pair<TreeNode*, int>> q;
        q.push({root, 0});

        //BFS
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            if (q.empty() || q.front().second != temp.second) {
                answer.push_back(temp.first->val);
            }
            if (temp.first->left != nullptr) {
                q.push({temp.first->left, temp.second+1});
            }
            if (temp.first->right != nullptr) {
                q.push({temp.first->right, temp.second+1});
            }
        }
        return answer;


    }
};