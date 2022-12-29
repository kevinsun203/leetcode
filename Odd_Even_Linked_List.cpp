using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        } 
        ListNode* oddHead = head;
        ListNode* evenHead = head->next;

        ListNode* oddTail = oddHead;
        ListNode* evenTail = evenHead;
        
        ListNode* p = evenHead->next;
        int count = 3;

        while (p != nullptr) {
            // Odd index
            if (count%2 != 0) {
                oddTail->next = p;
                oddTail = oddTail->next;
            }
            // Even index 
            else {
                evenTail->next = p;
                evenTail = evenTail->next;
            }
            p = p->next;
            count++;
        }

        // Attach even linked list after odd linked list
        oddTail->next = evenHead;
        evenTail->next = nullptr;
        return oddHead;
    }
};