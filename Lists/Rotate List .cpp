/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;
        ListNode *p = head, *tail, *newHead;
        int count = 0;
        while(p != NULL){
            count++;
            tail = p;
            p = p->next;
        }
        k = count - k % count;
        if(k == count) return head;
        p = head; k--;
        while(k != 0){
            k--;
            p = p->next;
        }
        newHead = p->next;
        p->next = NULL;
        tail->next = head;
        return newHead;
    }
};
