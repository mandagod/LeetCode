/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (NULL == head)
            return NULL;
            
        ListNode *pCurNode = head;
        for (int i = 1; i < n; i ++) {
            if (pCurNode->next) {
                pCurNode = pCurNode->next;
            }
            else {
                return NULL;
            }
        }
        
        // find the nTh of the end
        ListNode *pNBehinde = head;
        while(pCurNode->next) {
            pCurNode  = pCurNode->next;
            pNBehinde = pNBehinde->next;
        }
        
        //cout << pNBehinde->val << endl;
        
        // delete the nTh of the end
        if (pNBehinde == head) { // head node
            head = head->next;
            delete pNBehinde;
            pNBehinde = NULL; 
        }
        else if (NULL != pNBehinde->next) { // not head or tail
            ListNode *pNext = pNBehinde->next;
            pNBehinde->val = pNext->val;
            pNBehinde->next = pNext->next;
            delete pNext;
            pNext = NULL;
        }
        else { // tail
            ListNode *pNode = head;
            while(pNode->next != pNBehinde) {
                pNode = pNode->next;
            }
            pNode->next = NULL;
            
            delete pNBehinde;
            pNBehinde = NULL;
        }
        
        return head;
    }
};