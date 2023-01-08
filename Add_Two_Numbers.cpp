using namespace std;
//  Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer = new ListNode;
        ListNode* curr = answer;
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        int carry = 0;
        int temp, dig1,dig2;
        bool firstTime = true;
        while (ptr1 != nullptr || ptr2 != nullptr) {
            if (firstTime) {
                curr = answer;
                firstTime = false;
            } else {
                curr->next = new ListNode;
                curr = curr->next;
            }
            if (ptr1 != nullptr) {
                dig1 = ptr1->val;
            } else {
                dig1 = 0;
            }

            if (ptr2 != nullptr) {
                dig2 = ptr2->val;
            } else {
                dig2 = 0;
            }

            temp = dig1 + dig2 + carry;
            curr->val = temp % 10;
            carry = temp / 10;

            if (ptr1 != nullptr) {
                ptr1 = ptr1->next;
            } else {
                ptr1 = nullptr;
            }
            if (ptr2 != nullptr) {
                ptr2 = ptr2->next;
            } else {
                ptr2 = nullptr;
            }

        }
        if (carry > 0) {
            curr -> next = new ListNode;
            curr = curr->next;
            curr->val  = carry;
        }
        return answer;
        
    }
};