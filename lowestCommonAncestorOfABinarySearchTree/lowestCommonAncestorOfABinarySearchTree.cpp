// Source : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// Author : weekend27
// Date   : 2015-12-28

/**********************************************************************************

Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

**********************************************************************************/

// How to do it:
// ref: http://www.programcreek.com/2014/07/leetcode-lowest-common-ancestor-of-a-binary-search-tree-java/
// This problem can be solved by using BST property, i.e., left < parent < right for each node. There are 3 cases to handle.


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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* m = root;
        if (m->val > p->val && m->val < q->val){
            return m;
        }
        else if (m->val > p->val && m->val > q->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (m->val < p->val && m->val < q->val){
            return lowestCommonAncestor(root->right, p, q);
        }

        return root;
    }
};
