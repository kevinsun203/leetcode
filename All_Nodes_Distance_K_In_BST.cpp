#include <unordered_map>
#include <vector>
#include <queue>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    TreeNode* startingNode;
public:
    std::vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Build graph
        std::unordered_map<TreeNode*, std::vector<TreeNode*>> graph;

        fillGraph(graph, root, nullptr, target->val);

        std::vector<int> answer;

        std::queue<TreeNode*> q;
        std::unordered_map<TreeNode*, int> distances;
        distances[startingNode] = 0;
        q.push(startingNode);

        // BFS starting from target node
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            // Check the distance
            if (distances[curr] == k) {
                answer.push_back(curr->val);
            }
            std::vector<TreeNode*> adjacentNodes = graph[curr];

            for (int i=0; i<adjacentNodes.size(); i++) {
                if (distances.find(adjacentNodes[i]) == distances.end()) {
                    q.push(adjacentNodes[i]);
                    int distance = distances[curr] + 1;
                    distances[adjacentNodes[i]] = distance;
                }
            }
        }    
        return answer;
    }
    
    // Create graph from BST - preorder traversal
    void fillGraph(std::unordered_map<TreeNode*, std::vector<TreeNode*>>& graph, TreeNode* curr, TreeNode* parent, int target) {
        if (curr == nullptr) {
            return;
        }

        // Find starting node
        if (curr->val == target) {
            startingNode = curr;
        }

        // Insert current node into map
        if (graph.find(curr) == graph.end()) {
            graph[curr] = {};
        } 

        // Insert parent into list of adjacent nodes
        if (parent != nullptr) {
            graph[curr].push_back(parent);
        }

        // Insert children into list of adjacent nodes
        if (curr->left != nullptr) {
            graph[curr].push_back(curr->left);
        }
        if (curr->right != nullptr) {
            graph[curr].push_back(curr->right);
        }

        fillGraph(graph, curr->left, curr, target);
        fillGraph(graph, curr->right, curr, target);

        return;
    }
};