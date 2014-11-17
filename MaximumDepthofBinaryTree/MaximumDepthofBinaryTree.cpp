/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Hide Tags Tree Depth-first Search

Author: mandagod Nov 11, 2014
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
    int maxDepth(TreeNode *root) {
        if (root==NULL){
            return 0;
        }
        if (root->left==NULL && root->right==NULL){
            return 1;
        }
        int left=0;
        if (root->left){
            left = maxDepth(root->left) + 1 ;
        }
        int right=0;
        if (root->right){
            right = maxDepth(root->right) + 1;
        }
        
        return left>right ? left : right;        
    }
};