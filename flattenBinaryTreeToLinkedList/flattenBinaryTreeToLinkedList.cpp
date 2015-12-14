// Source : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Author : weekend27
// Date   : 2015-12-14

/**********************************************************************************

Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

**********************************************************************************/

// How to do it:
// look at the hints

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
    void flatten(TreeNode* root) {
        if (!root)
            return;

        vector<TreeNode*> nodeStack;
        TreeNode dummy(0);
        TreeNode* n = &dummy;

        nodeStack.push_back(root);

        while (!nodeStack.empty()){
            TreeNode* p = nodeStack.back();
            nodeStack.pop_back();

            // link to right child tree
            n->right = p;
            n = p;

            // push right child tree into stack
            if (p->right){
                nodeStack.push_back(p->right);
                p->right = NULL;
            }

            // push left child tree into stack
            if (p->left){
                nodeStack.push_back(p->left);
                p->left = NULL;
            }
        }
    }
};
