// Source : https://leetcode.com/problems/balanced-binary-tree/
// Author : weekend27
// Date   : 2015-12-11

/**********************************************************************************

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

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
    bool isBalanced(TreeNode* root) {
        // DFS, time complexity O(n)
        // corner case check
        if (root == NULL)
            return true;
        int isBalanced = height(root);
        if (isBalanced != -1)
            return true;
        else
            return false;
    }

    int height(TreeNode* root)
    {
        if (root == NULL)
            return 0;

        int lh = height(root->left);
        if (lh == -1)
            return -1;
        int rh = height(root->right);
        if (rh == -1)
            return -1;

        int dh = rh > lh ? (rh - lh) : (lh - rh);
        if (dh > 1)
            return -1;
        else
            return dh = (rh > lh ? rh : lh) + 1;
    }
};
