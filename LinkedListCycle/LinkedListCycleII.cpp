/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?

Hide Tags Linked List Two Pointers

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
    ListNode *detectCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode* slow = head;
        ListNode* fast = head;
        do{
            if( !slow || !fast ) 
                return NULL;
            slow = slow->next;
            fast = fast->next;
            
            if( fast ) 
                fast = fast->next;
            else 
                return NULL;
        }while( slow != fast ); 
        // fast two steps
        // slow single step
        
        slow = head;
        while( slow != fast ){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};