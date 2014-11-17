/*
Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

Hide Tags Linked List

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
    void reorderList(ListNode *head) {
        if (NULL == head || NULL == head->next)
            return;
            
        ListNode *pMid = findMidPos(head);
        pMid = reverseList(pMid);
        head = Merge(head, pMid);
    }
    
    ListNode* findMidPos(ListNode *head) {
        ListNode *p1, *p2, *p=NULL;
        p1 = p2 = head;
        
        while (p1!=NULL && p2!=NULL && p2->next!=NULL) {
            p = p1;
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        if (p!=NULL) {
            p->next = NULL;
        }
        return p1;
    }
    
    ListNode* reverseList(ListNode *head){
        ListNode* h = NULL;
        ListNode *p;
        while (head!=NULL){
            p = head;
            head = head->next;
            p->next = h;
            h = p;
        }
        return h;
    }
    
    ListNode* Merge(ListNode *h1, ListNode* h2) {
        if (NULL == h1)
            return h2;
        else if (NULL == h2)
            return h1;
            
        ListNode *pMergeHead = h1;
        h1 = h1->next;
        ListNode *pNode = pMergeHead;
        int flag = 2;
        while(NULL != h1 && NULL != h2) {
            if (2 == flag) {
                pNode->next = h2;
                pNode = h2;
                h2 = h2->next;
                flag = 1;
            }
            else if (1 == flag) {
                pNode->next = h1;
                pNode = h1;
                h1 = h1->next;
                flag = 2;
            }
        }
        
        pNode->next = (h1==NULL) ? h2 : h1;
        
        return pMergeHead;
    }
};