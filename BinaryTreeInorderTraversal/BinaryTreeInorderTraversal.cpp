/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Hide Tags Tree Hash Table Stack

Author: mandagod Nov 10, 2014
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<TreeNode *> stackTreeNode;
        vector<int> v;
        
        while (stackTreeNode.size()>0 || NULL!=root) {
            if (root != NULL) {
                stackTreeNode.push_back(root);
                root = root->left;
            }
            else {
                if (stackTreeNode.size()>0) {
                    root = stackTreeNode.back();
                    stackTreeNode.pop_back();
                    v.push_back(root->val);
                    root = root->right;
                }
            }
        }
        
        return v;
    }
};