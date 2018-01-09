#include <iostream>
using namespace std;

/*
不断把小的节点加过来
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* tail = head;

        while (l1 != NULL && l2 != NULL) {
        	if (l1->val <= l2->val) {
        		tail->next = l1;       		
        		l1 = l1->next;
        	} else {
        		tail->next = l2;
        		l2 = l2->next;
        	}
        	tail = tail->next;
        }

        if (l1 != NULL) {
        	tail->next = l1;
        }
        if (l2 != NULL) {
        	tail->next = l2;
        }

        return head->next;
    }
};