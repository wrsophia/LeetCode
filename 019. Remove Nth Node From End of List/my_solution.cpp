#include <iostream>
using namespace std;

/*
思路就是，用两个指针，让第一个指针先走n步，然后当第一个指针指向倒数第二个元素的时候
第二个指针指向的是要删除元素的前一个元素
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n == 0 || head == NULL) {
            return head;
        }
        
        ListNode* front = head, *back = head;
        for (int i = 0; i < n; ++i) {
            front = front->next;
        }
        if (front == NULL) {     // 当删掉的是头结点的时候，即n为链表长度的时候
            return back->next;
        }
        
        while (front->next != NULL) {
            front = front->next;
            back = back->next;
        }

        deleteNext(back);
        return head;       
    }
    
    void deleteNext(ListNode* primier) {
        primier->next = primier->next->next;
        
    }
};