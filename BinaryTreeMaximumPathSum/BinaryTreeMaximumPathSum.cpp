/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.

Hide Tags Tree Depth-first Search

Author: mandagod Nov 13, 2014
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
    int maxPathSum(TreeNode *root) {
        if(root == NULL) 
            return 0;
    
        int maxPath = INT_MIN;
        maxPathSumCal(root, maxPath);
    
        return maxPath;
    }
    
    int maxPathSumCal(TreeNode *root, int &maxPath) {
        if(root == NULL)
            return 0;
    
        int left = maxPathSumCal(root ->left, maxPath);
        int right= maxPathSumCal(root ->right,maxPath);
    
        int val = root ->val;
        int res = val + left > val + right? 
                 (val + left > val ? val + left : val) : 
                 (val + right > val ? val + right : val);
        int tmp = res > left + val + right ? res : left + val + right;
    
        if(maxPath < tmp) maxPath = tmp;
    
        return res;
    }
};