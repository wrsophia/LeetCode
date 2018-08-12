class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        ListNode *tail = &dummy, *node = head;

        while (node) {
            ListNode* now = node;

            while (node->next && node->next->val == node->val) {
                node = node->next;
            }

            if (node == now) {
                tail->next = node;
                tail = node;
            }
            node = node->next;
        }

        tail->next = NULL;
        return dummy.next;
    }
};
