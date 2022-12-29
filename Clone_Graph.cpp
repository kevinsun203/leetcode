#include "vector"
#include "queue"
#include "unordered_map"
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {

        if (node == nullptr) {
            return nullptr;
        }
        queue <Node*> q;

        // copy of graph as a map: key = original node, value = copied node using new
        unordered_map<Node*, Node*> gCopy;

        // Load given root node into queue and make a copy
        q.push(node);
        Node* newRoot = new Node(node->val);
        gCopy[node] = newRoot;

        // BFS
        while(!q.empty()) {
            Node* temp = q.front();
            q.pop();
            for (int i=0; i<temp->neighbors.size(); i++) {
                if (gCopy.find(temp->neighbors[i]) == gCopy.end()) {
                    // node has not been copied or visited yet
                    gCopy[temp->neighbors[i]] = new Node(temp->neighbors[i]->val);
                    q.push(temp->neighbors[i]);
                }
                // insert neighbor of copied node. This is irrespective of whether the node has 
                // been visited already
                gCopy[temp]->neighbors.push_back(gCopy[temp->neighbors[i]]);
            }
        }
        return newRoot;
    }
};