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
        ListNode root(0);    //在栈上申请内存，不然函数返回的时候如果不释放头结点，头结点的内存就泄露了
        ListNode* p = &root;
        
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {   //把最后一次进位的情况在这里考虑
            if (l1) {
                carry += l1->val;
                l1 = l1->next;
            }           
            if (l2) {
                carry += l2->val;
                l2 = l2->next;
            }            
            p->next = new ListNode(carry % 10);      // 这样就简洁多了     
            carry = carry / 10;
            p = p->next;
        }
        
        return root.next;
    }
};