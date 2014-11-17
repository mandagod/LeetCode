/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?

Hide Tags Tree Stack

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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<TreeNode *> stackTreeNode;
        vector<int> v;
        
        while (stackTreeNode.size()>0 || NULL!=root) {
            if (root != NULL) {
                v.push_back(root->val);
                if (root->right) {
                    stackTreeNode.push_back(root->right);
                }
                root = root->left;
            }
            else {
                if (stackTreeNode.size()>0) {
                    root = stackTreeNode.back();
                    stackTreeNode.pop_back();
                    v.push_back(root->val);
                    if (root->right) {
                        stackTreeNode.push_back(root->right);
                    }
                    root = root->left;
                }
            }
        }
        
        return v;
    }
};