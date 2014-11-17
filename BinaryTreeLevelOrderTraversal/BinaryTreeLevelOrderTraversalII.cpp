/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Hide Tags Tree Breadth-first Search

Author: mandagod Nov 09, 2014
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector< vector<int> > vv;
        if (NULL == root) {
            return vv;
        }
        
        deque<TreeNode *> dequeTreeNode;

        dequeTreeNode.push_back(root);
        while (dequeTreeNode.size() > 0) {
            vector<int> v;
            for (int i=dequeTreeNode.size(); i>0; i--) {
                TreeNode *pNode = dequeTreeNode.front();
                dequeTreeNode.pop_front();
                v.push_back(pNode->val);
                
                if (pNode->left) {
                    dequeTreeNode.push_back(pNode->left);
                }
                
                if (pNode->right) {
                    dequeTreeNode.push_back(pNode->right);
                }                 
            }
            vv.push_back(v);
        }
        
        reverse(vv.begin(), vv.end());
        
        return vv;        
    }
};