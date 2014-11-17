/*
Sort a linked list using insertion sort.

Hide Tags Linked List Sort

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
    ListNode *insertionSortList(ListNode *head) {
        if (NULL == head)
            return NULL;
            
        ListNode *pNode = head->next;
        ListNode *pSortHead = head;
        pSortHead->next = NULL;
        ListNode *pSortTail = pSortHead;
        
        while(NULL != pNode) {
            if (pNode->val >= pSortTail->val) { // intert after tail
                ListNode *pNextNode = pNode->next;
                pSortTail->next = pNode;
                pSortTail = pNode;
                pSortTail->next = NULL;
                pNode = pNextNode;
            }
            else if (pNode->val <= pSortHead->val) { // insert before head
                ListNode *pNextNode = pNode->next;
                pNode->next = pSortHead;
                pSortHead = pNode;
                pNode = pNextNode;
            }
            else {
                ListNode *pSortNode = pSortHead;
                ListNode *pSortNodePre = NULL;
                while(pNode->val > pSortNode->val) { // middle
                    pSortNodePre = pSortNode;
                    pSortNode = pSortNode->next;
                }
                ListNode *pNextNode = pNode->next;
                pSortNodePre->next = pNode;
                pNode->next = pSortNode;
                pNode = pNextNode;
            }
        }
        
        return pSortHead;
    }
};