/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
Hide Tags Tree Breadth-first Search Stack
Author: mandagod Nov 12, 2014
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > vv;
        if (NULL==root)
            return vv;
        
        stack<TreeNode *> levels[2];
        int current = 0;
        int next = 1;
        
        levels[current].push(root);
        while (!levels[0].empty() || !levels[1].empty()) {
            vector<int> v;
            for (int i=levels[current].size(); i>0; i--) {
                TreeNode *pNode = levels[current].top();
                levels[current].pop();
                v.push_back(pNode->val);
                
                if (current==0) {
                    if (NULL != pNode->left)
                        levels[next].push(pNode->left);
                    if (NULL != pNode->right)
                        levels[next].push(pNode->right);
                } else {
                    if (NULL != pNode->right)
                        levels[next].push(pNode->right);
                    if (NULL != pNode->left)
                        levels[next].push(pNode->left);                    
                }
            }
            
            if (levels[current].empty()) {
                vv.push_back(v);
                current = 1 - current;
                next = 1 - next;
            }
        }
    }
};