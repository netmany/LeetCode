/*
A linked list is given such that each node contains an additional random pointer 
which could point to any node in the list or null.

Return a deep copy of the list.
*/


/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return NULL;
        RandomListNode * first = head;
        while(first != NULL){
            RandomListNode *n = new RandomListNode(first->label);
            n->next = first->next;
            first->next = n;
            first = n->next;
        }
        first = head;
        while(first != NULL){
            if(first->random != NULL)
                first->next->random = first->random->next;
            first = first->next->next;
        }
        first = head;
        RandomListNode *second = head->next, *res = second;
        while(second != NULL){
            first->next = second->next;
            first = first->next;
            if(first == NULL) break;
            second->next = first->next;
            second = second->next;
        }
        return res;
    }
};
