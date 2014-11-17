/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ¡Ü m ¡Ü n ¡Ü length of list.

Hide Tags Linked List

Author : mandagod Nov 08, 2014
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (NULL == head || (m >= n))
            return head;
        
        ListNode fake(0); 
        fake.next = head;
        ListNode *pBegin = &fake;
        ListNode *pEnd   = &fake;
        
        int dist = n - m;
        while (pEnd && dist>0) {
            pEnd = pEnd->next;
            dist--;
        }
        while (pBegin && pEnd && m-1>0) {
            pBegin = pBegin->next;
            pEnd   = pEnd->next;
            m--;
        }
        // pBegin and pEnd one node before 2 and 4
        if (pBegin == NULL || pEnd == NULL || pEnd->next == NULL) {
            return head;
        }
        
        ListNode *p = pBegin->next; 
        ListNode *q = pEnd->next->next;
        ListNode *pHead = q;
        while (p != q) {
            ListNode *node = p->next;
            p->next = pHead;
            pHead = p;
            p = node;
        }
        pBegin->next = pHead;
        
        return fake.next;
    }
};