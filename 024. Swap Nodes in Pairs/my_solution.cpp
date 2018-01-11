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
    ListNode* swapPairs(ListNode* head) {
    	if (head == NULL) {
    		return head;
    	}

    	ListNode* newHead = new ListNode(0);
    	newHead->next = head;
    	ListNode *prev = newHead, *p = head, *q = p->next;

    	while (q != NULL) {
    		p->next = q->next;
    		prev->next = q;
    		q->next = p;

    		prev = p;
    		p = prev->next;
    		if (p == NULL) {
    			break;
    		}
    		q = p->next;
    	}    
    	return newHead->next;    
    }
};