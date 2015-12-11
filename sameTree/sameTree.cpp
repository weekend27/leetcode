// Source : https://leetcode.com/problems/same-tree/
// Author : weekend27
// Date   : 2015-12-11

/**********************************************************************************

Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // DFS, time complexity O(n)
        if (p == NULL && q == NULL)
            return true;
        else if (p == NULL || q == NULL)
            return false;
        if (p->val == q->val)
        {
            bool left = isSameTree(p->left, q->left);
            bool right = isSameTree(p->right, q->right);
            return left && right;
        }

        return false;
    }
};
