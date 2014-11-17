/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Hide Tags Divide and Conquer Linked List Heap

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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *p1 = NULL;
        ListNode *p2 = NULL;
        ListNode *p = NULL;
        while (lists.size() > 1) {
            p1 = lists.back();
            lists.pop_back();
            p2 = lists.back();
            lists.pop_back();
            p = mergeTwoLists(p1, p2);
            lists.insert(lists.begin(), p);
        }
        
        return lists.size() == 1 ? lists[0] : NULL;
    }

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