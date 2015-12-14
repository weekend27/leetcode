// Source : https://leetcode.com/problems/binary-tree-inorder-traversal/
// Author : weekend27
// Date   : 2015-12-14

/**********************************************************************************

Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

**********************************************************************************/

// How to do it:
// use a stack to store all root nodes that have been traversed
// left traversal over -> pop root -> start right tree traversal

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> values;
        if (root == NULL)
            return values;

        vector<TreeNode*> nodes;
        TreeNode* n = root;
        while (n || !nodes.empty()){
            // traverse left sub-tree, push root node into stack
            while (n){
                nodes.push_back(n);
                n = n->left;
            }

            if (!nodes.empty()){
                n = nodes.back();
                values.push_back(n->val);

                // pop root node, get right sub-tree
                nodes.pop_back();
                n = n->right;
            }
        }

        return values;
    }
};
