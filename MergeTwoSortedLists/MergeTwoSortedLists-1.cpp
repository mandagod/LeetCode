/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (NULL == l1)
            return l2;
        if (NULL == l2)
            return l1;
        
        ListNode *pMergedHead = NULL;
        if (l1->val < l2->val) {
            pMergedHead = l1;
            pMergedHead->next = mergeTwoLists(l1->next, l2);
        }
        else {
            pMergedHead = l2;
            pMergedHead->next = mergeTwoLists(l1, l2->next);
        }
        
        return pMergedHead;
    }
};