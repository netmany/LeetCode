/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        int carry = 0, t;
        ListNode *p = l1, *tail = p, *q = l2, *pre;
        while(p != NULL && q != NULL){
            t = p->val + q->val + carry;
            carry = t / 10;
            p->val = t % 10;
            tail = p;
            p = p-> next; q = q->next;
        }
        if(p == NULL){
            tail->next = q;
        }
        if(tail->next == NULL){
            if(carry != 0) tail->next = new ListNode(carry);
        } else {
            tail = tail->next;
            while(tail != NULL && carry != 0){
                t = tail->val + carry;
                carry = t / 10;
                tail->val = t % 10;
                pre = tail;
                tail = tail->next;
            }
            if(carry != 0) pre->next = new ListNode(carry);
        }
        return l1;
    }
};
