/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

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
        while(NULL != pListNode) {
            int CurVal = pListNode->val;
            ListNode *pNextNode = pListNode->next;
            while(pNextNode) {
                if (CurVal == pNextNode->val) {
                    pListNode->next = pNextNode->next;
                    delete pNextNode;
                    pNextNode = pListNode->next;
                }
                else {
                    break;
                }
            }
            pListNode = pNextNode;
        }
        
        return head;
    }
};