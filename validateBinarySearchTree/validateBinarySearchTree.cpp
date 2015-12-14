// Source : https://leetcode.com/problems/validate-binary-search-tree/
// Author : weekend27
// Date   : 2015-12-14

/**********************************************************************************

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

**********************************************************************************/

// How to do it:
// ref: http://fisherlei.blogspot.jp/2013/01/leetcode-validate-binary-search-tree.html
/*
对于每一个子树，限制它的最大，最小值，如果超过则返回false。
对于根节点，最大最小都不限制；
每一层节点，左子树限制最大值小于根，右子树最小值大于根；
但是比较有趣的是，在递归的过程中还得不断带入祖父节点的值。
*/


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
    bool isValidBST(TreeNode* root) {
        return verifyBST(root, false, false, 0, 0);
    }

    bool verifyBST(TreeNode* root, bool left, bool right, int lmax, int rmin){
        if (root == NULL)
            return true;

        if (left && root->val >= lmax)
            return false;
        if (right && root->val <= rmin)
            return false;

        bool leftValid = verifyBST(root->left, true, right, root->val, rmin);
        bool rightValid = verifyBST(root->right, left, true, lmax, root->val);

        return leftValid && rightValid;
    }
};
