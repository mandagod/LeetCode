/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *pListNode = head;
        ListNode *pPrev = NULL;
        bool bDup = false;
        while(NULL != pListNode) {
            int CurVal = pListNode->val;
            // 
            ListNode *pNextNode = pListNode->next;
            while(pNextNode) {
                if (CurVal == pNextNode->val) {
                    ListNode *pTmp = pNextNode;
                    pNextNode = pNextNode->next;
                    pListNode->next = pNextNode;
                    delete pTmp;
                    pTmp = NULL;
                    bDup = true;
                }
                else
                    break;
            }
            
            if (bDup) {
                if (NULL == pPrev) {
                    head = pNextNode;
                }else {
                    pPrev->next = pNextNode;
                }
                delete pListNode;
                pListNode = NULL;
                bDup = false;
            } else {
                pPrev = pListNode;
            }
            pListNode = pNextNode;
        }
        
        return head;
    }
};