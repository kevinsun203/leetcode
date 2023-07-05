#include <vector>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        std::vector<ListNode*> nodes;
        ListNode* p = head;

        // Put all node pointers into a vector
        while (p != nullptr) {
            nodes.push_back(p);
            p = p->next;
        }

        // Find index of node to remove 
        int index = nodes.size()-n;

        // Edge case where node to remove is the first one
        if (index == 0) {
            ListNode* tempHead = head->next;
            delete head;
            return tempHead;
        }

        // Get node before the one to remove
        ListNode* nodeBefore = nodes[index-1];
        
        nodeBefore->next = nodeBefore->next->next;
        delete nodes[index];
        return head;
    }
};