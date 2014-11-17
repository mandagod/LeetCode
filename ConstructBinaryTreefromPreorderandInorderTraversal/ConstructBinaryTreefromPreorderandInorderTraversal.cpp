/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

Hide Tags Tree Array Depth-first Search

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int preidx=0;
        return buildTree(preorder, preidx, inorder);
    }

    TreeNode *buildTree(vector<int> &preorder, int &predix, vector<int> &inorder) {
        if (preorder.size()<=0 || inorder.size()<=0)
            return NULL;
            
        TreeNode *root = new TreeNode(preorder[predix]);
        if (inorder.size()==1)
            return root;
            
        int i;
        for (i=0; i<inorder.size(); i++) {
            if (inorder[i]==preorder[predix])
                break;
        }
        
        if (i == inorder.size())
            return NULL;
            
        if (predix+1 >= preorder.size())
            return root;
            
        vector<int> v(inorder.begin(), inorder.begin()+i);
        if (v.size()>0) {
            predix++;
            root->left = buildTree(preorder, predix, v);
        }
        
        v.clear();
        v.assign(inorder.begin()+i+1, inorder.end());
        if (v.size()>0) {
            predix++;
            root->right = buildTree(preorder, predix, v);
        }
        return root;
    }
};
