/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

Hide Tags Tree Depth-first Search

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
    int sumNumbers(TreeNode *root) {
        if (NULL == root)
            return 0;
            
        vector<vector<int>> vv;
        vector<int> path;
        int currentSum = 0;
        hasPathSum(root, path, currentSum, vv);
        
        return currentSum;
    }

    void hasPathSum(TreeNode *root, vector<int> &path, int &currentSum, vector<vector<int>> &vRel) {
        path.push_back(root->val);
        
        // If node is leaf, the current sum of the path equals the sum, will print the path
        if (root->left == NULL && root->right == NULL) {
            /*cout << "A path is found: ";
            vector<int>::iterator iter = path.begin();
            for (; iter != path.end(); iter++)
                cout << *iter << " ";
            cout << endl;*/
            int sum = 0;
            vector<int> v;
            vector<int>::iterator iter = path.begin();
            for (; iter != path.end(); iter++) {
                v.push_back(*iter);
                sum = sum * 10 + *iter;
            }
            vRel.push_back(v);
            currentSum += sum;
        }
        
        // If ins't leaf node, traveral them
        if (root->left != NULL) {
            hasPathSum(root->left, path, currentSum, vRel);
        }
        if (root->right) {
            hasPathSum(root->right, path, currentSum, vRel);
        }
        
        // back to node of father
        path.pop_back();
    }
};