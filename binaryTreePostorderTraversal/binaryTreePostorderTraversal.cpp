// Source : https://leetcode.com/problems/binary-tree-postorder-traversal/
// Author : weekend27
// Date   : 2015-12-12

/**********************************************************************************

Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?

**********************************************************************************/

// How to do it:
// use a pre argument to check if the pre-node is a right or left sub-tree, then pop root;
// if not, push right and left sub-tree into stack


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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> values;
        if (root == NULL)
            return values;

        vector<TreeNode*> nodes;
        TreeNode* pre = NULL;

        nodes.push_back(root);

        while(!nodes.empty()){
            TreeNode* n = nodes.back();
            // we need to know pre before pop out of stack
            if ((n->left == NULL && n->right == NULL) ||
            (pre != NULL && (pre == n->left || pre == n->right))){
                values.push_back(n->val);
                nodes.pop_back();
                pre = n;
            } else {
                // push right sub-tree into stack
                if (n->right != NULL)
                    nodes.push_back(n->right);

                // push left sub-tree into stack
                if (n->left != NULL)
                    nodes.push_back(n->left);
            }
        }

        return values;
    }
};
