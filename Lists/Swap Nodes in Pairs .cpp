/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL || head -> next ==  NULL)
            return head;
        ListNode *newHead = head->next;
        ListNode *cur = head;
        ListNode *p, *q, *parent = newHead;
        while(cur != NULL && cur->next !=NULL){
            p = cur; q = cur->next;
            cur = cur->next->next;
            parent->next = q;
            q ->next= p;
            parent = p;
        }
        parent->next = cur;
        return newHead;
    }
};
