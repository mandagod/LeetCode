/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Hide Tags Tree Depth-first Search

Author:mandagod Nov 13, 2014
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
    void recoverTree(TreeNode *root) {
        if (NULL == root) 
            return;
    
        TreeNode p(numeric_limits<int>::min());
        TreeNode *a = NULL;
        TreeNode *b = NULL;
        TreeNode *pre = &p;

        recover(root, pre, a, b);
        if (a && b)
            swap(a->val, b->val);

        return;        
    }
    
    void recover(TreeNode *root, TreeNode *&pre, TreeNode *&a, TreeNode *&b) {
        if (NULL == root)
            return;

        recover(root->left, pre, a, b);
    
        if (root->val < pre->val){
            if (NULL == a) 
                a = pre; //a should change once.
            b = root; //b could change twice.
        }
        pre = root;
    
        recover(root->right, pre, a, b);
    }
};