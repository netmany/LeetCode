/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
    ListNode *mergeK(vector<ListNode *> &lists, int begin, int end){
        int len = end - begin;
        if(len == 0) return NULL;
        if(len == 1) return lists[begin];
        ListNode *left = mergeK(lists, begin, begin + len / 2);
        ListNode *right = mergeK(lists, begin + len / 2, end);
        ListNode head(0), *tail = &head;
        while(left != NULL && right != NULL){
            if(left->val < right->val){
                tail->next = left; left = left->next;
            }else{
                tail->next = right; right = right->next;
            }
            tail = tail->next;
        }
        if(left) tail->next = left;
        if(right) tail->next = right;
        return head.next;
    }
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return mergeK(lists, 0, lists.size());
    }
};
