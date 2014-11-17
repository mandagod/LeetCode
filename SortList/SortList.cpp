/*
Sort a linked list in O(n log n) time using constant space complexity.

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
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
            
        // find the middle place
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        while(p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        p2 = p1->next;
        p1->next = NULL;
        
        return mergeList(sortList(head), sortList(p2));
    }

    ListNode *mergeList(ListNode* pHead1, ListNode* pHead2) {
        if (NULL == pHead1)
            return pHead2;
        else if (NULL == pHead2)
            return pHead1;
        
        ListNode* pMergedHead = NULL;
    
        if(pHead1->val < pHead2->val)
        {
            pMergedHead = pHead1;
            pMergedHead->next = mergeList(pHead1->next, pHead2);
        }
        else
        {
            pMergedHead = pHead2;
            pMergedHead->next = mergeList(pHead1, pHead2->next);
        }
    
        return pMergedHead;
    }
};