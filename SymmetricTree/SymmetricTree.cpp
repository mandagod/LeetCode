Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

/*
For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

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
Hide Tags Tree Depth-first Search

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
    bool isSymmetric(TreeNode *root) {
        if (NULL == root)
            return true;
        if (random()%2){
            return isSymmetric1(root->left, root->right);
        }
        else
            return isSymmetric2(root->left, root->right);
    }
 
     Solution(){
        srand(time(NULL));
    }
    
    bool isSymmetric1(TreeNode *root1, TreeNode *root2) {
        if (NULL==root1 && NULL==root2)
            return true;
        
        if (NULL==root1 || NULL==root2)
            return false;
            
        if (root1->val != root2->val)
            return false;
        
        return isSymmetric1(root1->left, root2->right)
               && isSymmetric1(root1->right, root2->left);
    }
    
    bool isSymmetric2(TreeNode *root1, TreeNode *root2) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        
        q1.push(root1);
        q2.push(root2);
        
        while (q1.size()>0 && q2.size()>0) {
            TreeNode *pNode1 = q1.front();
            q1.pop();
            TreeNode *pNode2 = q2.front();
            q2.pop();
            
            if (NULL==pNode1 && NULL==pNode2)
                continue;
            if (NULL==pNode1 || NULL==pNode2)
                return false;
            if (pNode1->val != pNode2->val)
                return false;
            
            q1.push(pNode1->left);
            q2.push(pNode2->right);
            
            q1.push(pNode1->right);
            q2.push(pNode2->left);
        }
        return true;
    }
};
