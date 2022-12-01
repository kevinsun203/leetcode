using namespace std;

// /**
//  * Definition for singly-linked list.
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
        ListNode* p = head;

        // Find n-th term and store it in p
        for (int i=0; i<n-1; i++) {
            p=p->next;
        }

        ListNode* nth = head;
        ListNode* lag = nullptr;
        while (p->next != nullptr) {
            p = p->next;
            lag = nth;
            nth = nth->next;
        }   

        if (lag != nullptr) {
            lag->next = nth->next;
            delete nth;
        } else {
            lag = head;
            head = head->next;
            delete lag;
        }
        return head;
    }
};