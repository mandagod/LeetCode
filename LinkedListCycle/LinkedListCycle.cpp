/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

Hide Tags Linked List Two Pointers

Author: mandagod Nov 07, 2014
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
    bool hasCycle(ListNode *head) {
        if (NULL == head)
            return false;
            
        ListNode *pSlow = head;
        ListNode *pFast = head->next;
        
        while (true) {
            if (NULL == pFast || NULL == pFast->next)
                return false;
            else if (pFast == pSlow || pFast->next == pSlow)
                return true;
            else {
                pSlow = pSlow->next;
                pFast = pFast->next->next;
            }
        }
    }
};