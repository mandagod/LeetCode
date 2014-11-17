/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

Hide Tags Depth-first Search Linked List

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
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (NULL == head)
            return NULL;
        if (NULL == head->next) {
            return new TreeNode(head->val);
        }
        
        ListNode *pMid = findMidPos(head);
        TreeNode *pTreeNode = new TreeNode(pMid->val);
        pTreeNode->left = sortedListToBST(head);
        pTreeNode->right = sortedListToBST(pMid->next);
        
        return pTreeNode;
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
};