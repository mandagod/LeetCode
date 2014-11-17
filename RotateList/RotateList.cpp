/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

Hide Tags Linked List Two Pointers

Author: mandagod Nov 08, 2014
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
        if (NULL == head || k <= 0)
            return head;
        
        ListNode *p1, *p2=head;
        for (int i=0; i<k; i++) {
            if (p2->next != NULL) {
                p2 = p2->next;
            }
            else
                p2 = head; // the k morn than the len of the list
        }
        
        for (p1=head; p2->next != NULL; p1=p1->next, p2=p2->next)
            ;
            
        p2->next = head;
        head = p1->next;
        p1->next = NULL;
        
        return head;
    }
};