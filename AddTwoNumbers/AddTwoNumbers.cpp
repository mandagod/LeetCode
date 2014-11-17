/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Hide Tags Linked List Math

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (NULL == l1)
            return l2;
        else if (NULL == l2)
            return l1;
        
        ListNode *pNewHead = NULL;
        ListNode *pNewTail = NULL;
        int carry = 0;
        while (NULL != l1 && NULL != l2) {
            ListNode *pNode = new ListNode((l1->val + l2->val + carry) % 10);
            carry = (l1->val + l2->val + carry) / 10;
            
            if (NULL == pNewHead) {
                pNewHead = pNode;
                pNewTail = pNewHead;
                pNewTail->next = NULL;
            } else {
                pNewTail->next = pNode;
                pNewTail = pNode;
                pNewTail->next = NULL;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        
        ListNode *pLast = (NULL == l1) ? l2 : l1;
        
        while (NULL != pLast) {
            ListNode *pNode = new ListNode((pLast->val + carry) % 10);
            pNewTail->next = pNode;
            pNewTail = pNode;
            pNewTail->next = NULL;
                
            carry = (pLast->val + carry) / 10;
            pLast = pLast->next;
        }
            
        if (carry) {
            ListNode *pNode = new ListNode(carry);
            pNewTail->next = pNode;
            pNewTail = pNode;
            pNewTail->next = NULL;              
        }
        
        return pNewHead;
    }
};