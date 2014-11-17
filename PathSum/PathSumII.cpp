/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> vv;
        if (NULL == root)
            return vv;

        vector<int> path;
        int currentSum = 0;
        bool bResult = false;
        hasPathSum(root, sum, path, currentSum, vv, bResult);
        
        return vv;
    }
    
    void hasPathSum(TreeNode *root, int sum, vector<int> &path, int currentSum, vector<vector<int>> &vRel, bool &bRel) {
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
                vector<int> v;
                vector<int>::iterator iter = path.begin();
                for (; iter != path.end(); iter++)
                    v.push_back(*iter);
                vRel.push_back(v);
                bRel = true;
                //return;
            }
        }
        
        // If ins't leaf node, traveral them
        if (root->left != NULL) {
            hasPathSum(root->left, sum, path, currentSum, vRel, bRel);
        }
        if (root->right) {
            hasPathSum(root->right, sum, path, currentSum, vRel, bRel);
        }
        
        // back to node of father
        path.pop_back();
    }
};