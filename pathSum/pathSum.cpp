// Source : https://leetcode.com/problems/path-sum/
// Author : weekend27
// Date   : 2015-12-11

/**********************************************************************************

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

**********************************************************************************/

// How to do it:
// DFS
// time complexity: O(n)


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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return false;

        return DFS(sum, root, 0);
    }

    bool DFS(int target, TreeNode* root, int sum){
        if (root == NULL)
            return false;

        sum += root->val;
        if (root->left == NULL && root->right == NULL){
            if (sum == target)
                return true;
            else
                return false;
        }

        bool ls = DFS(target, root->left, sum);
        bool rs = DFS(target, root->right, sum);
        return ls || rs;
    }
};
