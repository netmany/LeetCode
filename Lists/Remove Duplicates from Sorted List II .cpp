/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode newHead(0), *p = &newHead, *pre = head, *q;
        while(pre != NULL){
            q = pre->next;
            while(q!= NULL && q->val == pre->val) q = q->next;
            if(q == pre->next){
                p->next = pre;
                p = p->next;
            }
            pre = q;
        }
        p->next = NULL;
        return newHead.next;
    }
};
