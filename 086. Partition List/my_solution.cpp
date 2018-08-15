/**
 * 用一个指针记录下一个符合条件的节点该接在哪里，一个指针去找节点，如果碰到<x的节点就接过去，如果prev->next恰好是<x的节点，prev也要前移
 * 如果碰到>=x的节点，只有left和curr指针需要前移
 */


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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy(0);
        ListNode* prev = &dummy;
        prev->next = head;
        ListNode* curr = head, *left = prev;

        while (curr != NULL) {
            if (curr->val >= x) {
                left = curr;
            } else if (curr->val < x && prev != left) {
                left->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
                prev = prev->next;
            } else {
                left = left->next;
                prev = prev->next;
            }
            curr = left->next;
        }
        return dummy.next;

    }
};
