/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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
    ListNode *partition(ListNode *head, int x) {
        ListNode fh(0), sh(0), *first = &fh, *second = &sh, *p = head;
        while(p != NULL){
            if(p->val < x) {
                first->next = p;
                first = first->next;
            }else{
                second->next = p;
                second = second->next;
            }
            p = p->next;
        }
        second->next = NULL;
        first->next = sh.next;
        return fh.next;
    }
};
