// Source : https://leetcode.com/problems/symmetric-tree/
// Author : weekend27
// Date   : 2015-12-11

/**********************************************************************************

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

**********************************************************************************/

// How to do it:
// 3 features:
// 1. left->val == right->val
// 2. left->left, right->right
// 3. left->right, right->left


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
    bool isSymmetric(TreeNode* root) {
        // recursion
        if (root == NULL)
            return true;
        return mirror(root->left, root->right);
    }

    bool mirror(TreeNode* left, TreeNode* right){
        if (left == NULL && right == NULL)
            return true;
        else if (left == NULL || right == NULL)
            return false;

        bool mirr1 = left->val == right->val;
        bool mirr2 = mirror(left->left, right->right);
        bool mirr3 = mirror(left->right, right->left);

        return mirr1 && mirr2 && mirr3;
    }
};
