/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

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
    ListNode *partition(ListNode *head, int x) {
        if (NULL == head || NULL == head->next)
            return head;
            
        ListNode *pLeftHead = NULL;
        ListNode *pLeftTail = NULL;
        
        ListNode *pNode = head;
        ListNode *pPrev = NULL;
        while (NULL != pNode) {
            if (pNode->val < x) {
                if (pLeftHead == NULL) {
                    pLeftHead = pNode;
                    pLeftTail = pLeftHead;
                } else {
                    pLeftTail->next = pNode;
                    pLeftTail = pNode;
                }
                
                if (NULL == pPrev) {
                    pNode = pNode->next;
                    head = pNode;
                } else {
                    pPrev->next = pNode->next;
                    pNode = pNode->next;
                }
                
                pLeftTail->next = NULL;
            } else {
                pPrev = pNode;
                pNode = pNode->next;
            }
        }
        
        if (NULL != pLeftTail)
            pLeftTail->next = head;
        
        return (NULL == pLeftHead) ? head : pLeftHead;
    }
};