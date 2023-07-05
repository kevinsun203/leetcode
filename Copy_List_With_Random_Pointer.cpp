#include <unordered_map>
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
        std::unordered_map<Node*, Node*> mapping; // Key: node from original list
                                                 // Value: node in deep copy list
        
        if (head == nullptr) {
            return nullptr;
        }
        Node* newHead = new Node(head->val);
        
        mapping[head] = newHead;
        Node* curr = head;

        while (curr != nullptr) {
            // Create copy of current node if non-existent
            if (mapping.find(curr) == mapping.end()) {
                Node* copyCurr = new Node(curr->val);
                mapping[curr] = copyCurr;
            }
            
            // Create copy of next node if non existent
            if (curr->next != nullptr && mapping.find(curr->next) == mapping.end()) {
                mapping[curr->next] = new Node(curr->next->val);
            }
            Node* nextCopy = curr->next == nullptr ? nullptr : mapping[curr->next];
            mapping[curr]->next = nextCopy;

            // Create copy of random node if non existent
            if (curr->random != nullptr && mapping.find(curr->random) == mapping.end()) {
                mapping[curr->random] = new Node(curr->random->val);
            }
            Node* randomCopy = curr->random == nullptr ? nullptr : mapping[curr->random];
            mapping[curr]->random = randomCopy;

            curr = curr->next;
        }

        return newHead;
    }
};