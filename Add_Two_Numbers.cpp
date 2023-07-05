
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool firstDigit = true;
        ListNode* newHead = new ListNode(0);
        ListNode* lag;
        int carry = 0;
        int newDigit;

        while (l1 != nullptr || l2 != nullptr) {

            // Get value of both nodes
            int l1Val = l1 == nullptr ? 0 : l1->val;
            int l2Val = l2 == nullptr ? 0 : l2->val;

            // Get digit
            newDigit = l1Val + l2Val + carry;

            // Create carry for next digit
            if (newDigit >= 10) {
                carry = newDigit / 10;
                newDigit = newDigit % 10;
            } else {
                carry = 0;
            }

            if (firstDigit) {
                newHead->val = newDigit;
                firstDigit = false;
                lag = newHead;
            } else {
                lag->next = new ListNode(newDigit);
                lag = lag->next;
            }

            // Get next node
            l1 = l1 == nullptr || l1->next == nullptr ? nullptr : l1->next;
            l2 = l2 == nullptr || l2->next == nullptr ? nullptr : l2->next;

        }

        // If the final digit has a carry, create another node
        if (carry != 0) {
            lag->next = new ListNode(carry);
        }

        return newHead;
    }
};