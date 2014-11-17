/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

Hide Tags Linked List

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
    ListNode *swapPairs(ListNode *head) {
        if (NULL == head)
            return NULL;
            
        ListNode *pNode1 = head;
        ListNode *pNode2 = head->next;
        ListNode *pNode1Prev = NULL;
        ListNode *pNode2Next = NULL;
        while(NULL != pNode2) {
            pNode2Next = pNode2->next;
            
            if (NULL == pNode1Prev) {
                head = pNode2;
            }
            else
                pNode1Prev->next = pNode2;    
                
            pNode2->next = pNode1;
            pNode1->next = pNode2Next;
            
            pNode1Prev = pNode1;
            pNode1 = pNode1->next;
            if (NULL != pNode1 && NULL != pNode1->next) {
                pNode2 = pNode1->next;               
            }
            else
                pNode2 = NULL;
        }
        
        return head;
    }
};