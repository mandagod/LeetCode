/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Hide Tags Tree Dynamic Programming

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
    vector<TreeNode *> generateTrees(int n) {
        return generateTree(1, n);    
    }
    
    vector<TreeNode *> generateTree(int from, int to)
    {
        vector<TreeNode *> ret;
        if(to - from < 0) ret.push_back(0);
        if(to - from == 0) ret.push_back(new TreeNode(from));
        if(to - from > 0) {
            for(int i=from; i<=to; i++) {
                vector<TreeNode *> l = generateTree(from, i-1);
                vector<TreeNode *> r = generateTree(i+1, to);
    
                for(int j=0; j<l.size(); j++) {
                    for(int k=0; k<r.size(); k++) {
                        TreeNode * h = new TreeNode (i);
                        h->left = l[j];
                        h->right = r[k];
                        ret.push_back(h);
                    }
                }
            }
        }
        return ret;
    }
};