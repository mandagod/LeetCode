/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Hide Tags Tree Depth-first Search

Author: mandagod Nov 08, 2014
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
    bool isBalanced(TreeNode *root) {
        int depth = 0;
        return isBalanced(root, &depth);
    }
 /* Another bad method
    bool isBalanced(TreeNode *root) {
        if (NULL == root)
            return true;
        
        int left = treeDepth(root->left);
        int right = treeDepth(root->right);
        int diff = left - right;
        if (diff > 1|| diff < -1)
            return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
 */
    bool isBalanced(TreeNode *root, int *pDepth) {
        if (NULL == root) {
            *pDepth = 0;
            return true;
        }
        
        int left, right;
        if (isBalanced(root->left, &left) &&
            isBalanced(root->right, &right)) {
            int diff = left - right;
            if (diff<=1 && diff>=-1) {
                *pDepth = 1 + (left > right ? left : right);
                return true;
            }
        }
        
        return false;
    }
    
    int treeDepth(TreeNode *root) {
        if (NULL == root)
            return 0;
            
        int nLeft = treeDepth(root->left);
        int nRight = treeDepth(root->right);
        
        return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
    }
};