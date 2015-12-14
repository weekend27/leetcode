// Source : https://leetcode.com/problems/path-sum-ii/
// Author : weekend27
// Date   : 2015-12-14

/**********************************************************************************

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

**********************************************************************************/

// How to do it:
// really like pathSum.cpp
// differences are just arguments for the function


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> path;
        if (root == NULL)
            return path;
        vector<int> curr;
        DFS(path, curr, sum, 0, root);
        return path;
    }

    void DFS(vector<vector<int>>& path, vector<int> curr, int sum, int tmp, TreeNode* root){
        if (root == NULL)
            return;
        tmp += root->val;
        curr.push_back(root->val);
        if (tmp == sum){
            if (root->left == NULL && root->right == NULL){
                path.push_back(curr);
                return;
            }
        }
        DFS(path,curr,sum,tmp,root->left);
        DFS(path,curr,sum,tmp,root->right);
    }
};
