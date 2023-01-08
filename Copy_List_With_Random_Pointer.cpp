#include "unordered_map"
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> clone;
        Node* curr = head;

        Node* newHead = nullptr;
        bool firstTime = true;
        while (curr != nullptr) {
            if (clone.find(curr) == clone.end()) {
                clone[curr] = new Node(curr->val);
            }
            if (curr->next != nullptr && clone.find(curr->next) == clone.end()) {
                clone[curr->next] = new Node(curr->next->val);
            }
            clone[curr]->next = curr->next == nullptr ? nullptr : clone[curr->next];
            
            if (curr->random != nullptr && clone.find(curr->random) == clone.end()) {
                clone[curr->random] = new Node(curr->random->val);
            } 
            clone[curr]->random = curr->random == nullptr ? nullptr : clone[curr->random];
            
            if (firstTime) {
                newHead = clone[curr];
                firstTime = false;
            }
            curr = curr->next;
        }
        return newHead;
    }
};