/*
Sort a linked list in O(n log n) time using constant space complexity.
*/

//--------------------------------------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode *merge(ListNode *first, ListNode *second) {
        ListNode head(0), *tail = &head;
        while(first != NULL && second != NULL){
            if(first->val < second->val){
                tail->next = first; 
                first = first->next;
            }else{
                tail->next = second;
                second = second->next;
            }
            tail = tail->next;
        }
        if(first == NULL) tail->next = second;
        if(second == NULL) tail->next = first;
        return head.next;
        
    }
public:
    ListNode *sortList(ListNode *head) {
        ListNode *pre = head, *slow = pre, *fast  = slow;
        while(fast != NULL && fast->next != NULL){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(slow == head) return head;
        pre->next = NULL;
        return merge(sortList(head), sortList(slow));
    }
};
