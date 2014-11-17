/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
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