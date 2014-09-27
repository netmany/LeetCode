/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    void interleave(ListNode* first, ListNode* second){
        ListNode res(0), *tail = &res, *p, *q;
        while(first != NULL && second != NULL){
            p = first->next; q = second->next;
            tail->next = first; first->next = second; tail = second;
            first = p; second = q;
        }
        if(first == NULL) tail->next = second;
        if(second == NULL) tail->next = first;
    }
    ListNode* reverse(ListNode* head){
        ListNode res(0);
        ListNode *p = head, *q;
        while(p != NULL){
            q = p->next;
            p->next = res.next;
            res.next = p;
            p = q;
        }
        return res.next;
    }
public:
    void reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL) return;
        ListNode *fast = head, *slow = head, *pre;
        while(fast != NULL && fast->next != NULL){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        interleave(head, reverse(slow));
    }
};
