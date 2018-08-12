/**
 * 为了把头结点的选择也包括在过程里，新创建一个dummy节点
 * 第23行，加上curr->next != NULL是因为，如果不加，又碰上最后一个节点不该删掉的情况，会在第32行把最后节点略过
 * 最后，如果new了节点，就要在函数结尾delete掉，更好的方法是ListNode dummy(0)
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* first = new ListNode(0);
        first->next = head;
        ListNode* prev = first, *curr = head;

        while (curr != NULL && curr->next != NULL) {  
            if (curr->next != NULL && curr->next->val != curr->val) {
                prev->next = curr;
                prev = prev->next;
            } else {
                while (curr->next != NULL && curr->val == curr->next->val) {
                    curr = curr->next;
                }
            }
            curr = curr->next;
        }
        prev->next = curr;
        delete first;
        return first->next;
    }
};
