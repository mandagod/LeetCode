/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

Hide Tags Hash Table Linked List

Author: mandagod Nov 08, 2014
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        cloneNodes(head);
        connectRandomNodes(head);
        return reconnectNodes(head);
    }
    
	// Clone every node
    void cloneNodes(RandomListNode *head) {
        RandomListNode *pNode = head;
        while (NULL != pNode) {
            RandomListNode *pClone = new RandomListNode(pNode->label);
            pClone->next = pNode->next;
            pNode->next = pClone;
            pNode = pClone->next;
        }
    }
    
	// Set random of cloned nodes
    void connectRandomNodes(RandomListNode *head) {
        RandomListNode *pNode = head;
        while (NULL != pNode) {
            RandomListNode *pClone = pNode->next;
            if (NULL != pNode->random) {
                pClone->random = pNode->random->next;
            }
            pNode = pClone->next;
        }
    }
    
	// pcik up of the copy
    RandomListNode *reconnectNodes(RandomListNode *head) {
        RandomListNode *pNode = head;
        RandomListNode *pCloneHead = NULL;
        RandomListNode *pCloneNode = NULL;
        
        if (NULL != pNode) {
            pCloneHead = pCloneNode = pNode->next;
            pNode->next = pCloneNode->next;
            pNode = pNode->next;
        }
        
        while (NULL != pNode) {
            pCloneNode->next = pNode->next;
            pCloneNode = pCloneNode->next;
            pNode->next = pCloneNode->next;
            pNode = pNode->next;
        }
        
        return pCloneHead;
    }
};