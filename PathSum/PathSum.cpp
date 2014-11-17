/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

Hide Tags Tree Depth-first Search
Author: mandagod Nov 07, 2014
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
    bool hasPathSum(TreeNode *root, int sum) {
        if (NULL == root) {
            return false;
        }
        
        vector<int> path;
        int currentSum = 0;
        bool bResult = false;
        hasPathSum(root, sum, path, currentSum, bResult);
        
        return bResult;
    }
    
    void hasPathSum(TreeNode *root, int sum, vector<int> &path, int currentSum, bool &bRel) {
        currentSum += root->val;
        path.push_back(root->val);
        
        // If node is leaf, the current sum of the path equals the sum, will print the path
        if (root->left == NULL && root->right == NULL) {
            if (currentSum == sum) {
                /*cout << "A path is found: ";
                vector<int>::iterator iter = path.begin();
                for (; iter != path.end(); iter++)
                    cout << *iter << " ";
                cout << endl;*/
                bRel = true;
                return;
            }
        }
        
        // If ins't leaf node, traveral them
        if (root->left != NULL) {
            hasPathSum(root->left, sum, path, currentSum, bRel);
        }
        if (root->right) {
            hasPathSum(root->right, sum, path, currentSum, bRel);
        }
        
        // back to node of father
        path.pop_back();
    }
};