/**
 * 两个指针，一个指针先走k步，另一个指针(first)再一起走，当前面(second)的指针走到最后的NULL的时候
 * 刚好可以另 second->next = head, first->next = NULL
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) {
            return head;
        }

        ListNode *first = head, *second = head;

        // 统计节点数，不然得超时
        int nodes = 0;
        while (first != NULL) {
            ++nodes;
            first = first->next;
        }
        first = head;

        k %= nodes;
     
        while (k > 0) {
            second = second->next;
            --k;
        }

        if (second == NULL) {
            return head;
        }

        while (second->next != NULL) {
            second = second->next;
            first = first->next;
        }

        second->next = head;
        ListNode* newHead = first->next;
        first->next = NULL;
        return newHead;
    }
};
