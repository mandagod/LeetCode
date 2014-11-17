/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

Hide Tags Tree Depth-first Search
Author :mandagod Nov 12, 2014
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
    void flatten(TreeNode *root) {
        if (NULL == root)
            return;
        stack<TreeNode *> treeStack;
        deque<TreeNode *> treeQue;
        
        TreeNode *pNode = root;
        while(treeStack.size()>0 || NULL != pNode) {
            if (pNode != NULL) {
                if (NULL != pNode->right)
                    treeStack.push(pNode->right);
                treeQue.push_back(pNode);
                pNode = pNode->left;
            } else {
                if (treeStack.size()>0) {
                    pNode = treeStack.top();
                    treeStack.pop();
                }
            }
        }
        
        if (treeQue.size()>0) {
            root = treeQue.front();
            treeQue.pop_front();
            root->right = NULL;
            root->left = NULL;
            pNode = root;
        }
        while (treeQue.size()>0) {
            TreeNode *pTmp = treeQue.front();
            treeQue.pop_front();
            pTmp->right = NULL;
            pTmp->left = NULL;
            pNode->right = pTmp;
            pNode = pNode->right;
        }
    }
};