 #include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);    //这个节点没卵用
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* p = result;
        
        int carry = 0;
        int val = 0;
        while (p1 != NULL || p2 != NULL) {
            if (p1 == NULL) {
                val = p2->val + carry;               
                p2 = p2->next;
            } else if (p2 == NULL) {
                val = p1->val + carry;                
                p1 = p1->next;
            } else {
                val = p1->val + p2->val + carry;                    
                p1 = p1->next;
                p2 = p2->next;
            }
            carry = 0;
            if (val >= 10) {
                carry = 1;
                val -= 10;
            }
            p->next = new ListNode(val);
            p = p->next;
        }
        if (carry == 1) {      // 这个很容易忘
            p->next = new ListNode(1);
        }
        return result->next;
    }
};