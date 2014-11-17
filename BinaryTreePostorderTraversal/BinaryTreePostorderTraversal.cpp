/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?

Hide Tags Tree Stack

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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> v;
        if (NULL == root)
            return v;
        
        if (NULL != root->left)
            postorderTraversal(root->left, v);
        if (NULL != root->right)
            postorderTraversal(root->right, v);
        
        v.push_back(root->val);
        
        return v;
    }
    
    void postorderTraversal(TreeNode *root, vector<int> &v) {
        if (NULL==root)
            return;
        
        if (NULL != root->left)
            postorderTraversal(root->left, v);
        if (NULL != root->right)
            postorderTraversal(root->right, v);
        
        v.push_back(root->val);       
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        vector<int> temp;
        while(true)
        {
            if (cur == NULL)  // If the current branch is finished, then go back to the most recent unvisited branch
            {
                if (!s.empty()) {
                    cur = s.top(); s.pop(); continue;
                    
                } // Checked the first unvisited branch
                else break;
            }
            temp.push_back(cur->val); // Add the current value to the FRONT of list
            s.push(cur->left);         // Push the left child to the stack
            cur = cur->right;          // Go the right child
        }
        // Don't forget to reverse the 'right-to-left' pre-order traversal!
        return vector<int>(temp.rbegin(), temp.rend()); 
    }
};