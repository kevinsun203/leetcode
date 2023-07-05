
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <stack>

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head->next == nullptr || head->next->next == nullptr) {
            return;
        }

        std::stack<ListNode*> stck;
        // Traverse the list and put them into a stack
        ListNode* p = head->next;
        while (p != nullptr) {
            stck.push(p);
            p = p->next;
        }

        int size = stck.size();
        ListNode* saveHead = head;
        
        // Only the top half of the stack will be re-inserted into the list
        size = size % 2 == 0 ? size / 2: size / 2 + 1;

        // Re-insert top half of the stack at every other node
        for (int i=0; i<size; i++) {
            p = stck.top();
            stck.pop();
            ListNode* temp = head->next;
            head->next = p;
            p->next = temp;
            head = temp;
        }
        
        // Set new tail
        head->next = nullptr;

        head = saveHead;
    }
};