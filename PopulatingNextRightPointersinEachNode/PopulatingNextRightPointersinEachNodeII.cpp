/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
Hide Tags Tree Depth-first Search

Author: mandagod Nov 13, 2014
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (NULL == root)
            return;
            
        deque<TreeLinkNode *> dequeTreeNode;
        dequeTreeNode.push_back(root);
        while (dequeTreeNode.size() > 0) {
            TreeLinkNode *pNode = NULL;
            for (int i=dequeTreeNode.size(); i>0; i--) {
                TreeLinkNode * pTmp = dequeTreeNode.front();
                if (pNode == NULL)
                    pNode = pTmp;
                else {
                    pNode->next = pTmp;
                    pNode = pTmp;
                }
                dequeTreeNode.pop_front();
                
                if (pNode->left) {
                    dequeTreeNode.push_back(pNode->left);
                }
                
                if (pNode->right) {
                    dequeTreeNode.push_back(pNode->right);
                } 
            }
        }          
    }
};