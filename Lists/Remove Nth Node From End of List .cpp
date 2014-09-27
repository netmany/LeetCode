/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head == NULL) return head;
        if(head->next == NULL) return NULL;
        ListNode *p = head;
        int i = n + 1;
        while(i > 0 && p != NULL) {
            p = p->next;
            i--;
        }
        if(i > 0) return head->next;
        ListNode *q = head;
        while(p != NULL){
            p = p->next;
            q = q->next;
        }
        q->next = q->next->next;
        return head;
    }
};
