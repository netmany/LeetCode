/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(head == NULL || m == n) return head;
        ListNode *p = head, *pre;
        int k = 1;
        while(k < m) {
            pre = p;
            p = p->next;
            k++; 
        }
        ListNode newHead(0), *tail = p, *q = p, *t;
        if(m == 1) p = &newHead;
        else p = pre;
        while(k < n){
            t = q; q = q->next;
            t->next = p->next;
            p->next = t;
            k++;
        }
        tail->next = q->next;
        q->next = p->next;
        p->next = q;
        if(m == 1) return newHead.next;
        else return head;
    }
};
