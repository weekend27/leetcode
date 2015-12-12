// Source : https://leetcode.com/problems/binary-tree-preorder-traversal/
// Author : weekend27
// Date   : 2015-12-12

/**********************************************************************************

Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?

**********************************************************************************/

// How to do it:
// use a stack to save right sub-tree first, and then save left sub-tree

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> values;
        if (root == NULL)
            return values;

        vector<TreeNode*> nodes;

        // first push root into stack
        nodes.push_back(root);

        while (!nodes.empty()){
            TreeNode* n = nodes.back();
            values.push_back(n->val);

            // pop accessed node
            nodes.pop_back();

            // push right child into stack to save
            if (n->right)
                nodes.push_back(n->right);

            // push left child into stack to save
            if (n->left)
                nodes.push_back(n->left);
        }
        return values;
    }
};
