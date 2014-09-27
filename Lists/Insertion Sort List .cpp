/*
Sort a linked list using insertion sort.
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
    ListNode *insertionSortList(ListNode *head) {
        ListNode res(0), *second = head;
        ListNode *p, *q;
        while(second != NULL){
            p = &res; q = second;
            while(p->next != NULL && p->next->val < q->val) p = p->next;
            second = q->next;
            if(p->next == NULL) {
                p->next = q;
                q->next = NULL;
            }else{
                q->next = p->next;
                p->next = q;
            }
        }
        return res.next;
    }
};
