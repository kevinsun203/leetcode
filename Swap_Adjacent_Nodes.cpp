using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* first = nullptr;
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* second = head;
        ListNode* temp;  
        do {
            if (second == head) {
                second = second->next;
                first = head;
            } else {
                first = second->next;
                second = second->next->next;
            }
            int firstTemp = first->val;
            int secondTemp = second->val;
            first->val = secondTemp;
            second->val = firstTemp;            
        } while (second->next != nullptr && second->next->next != nullptr);

        return head;
    }
};