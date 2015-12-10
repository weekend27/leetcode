// Source : https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Author : weekend27
// Date   : 2015-12-10

/**********************************************************************************

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

**********************************************************************************/

// How to do it:
// recursively traverse the binary tree, when reaching leaf node , record the depth

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
    int num;
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;

        // Initialize num to be min
        num = numeric_limits<int>::min();
        travel(root, 1);
        return num;
    }

    void travel(TreeNode* node, int level){
        // if no left child and no right child, it reaches leaf node
        if (!node->left && !node->right){
            num = max(num, level);
            return;
        }

        if (node->left)
            travel(node->left, level+1);

        if (node->right)
            travel(node->right, level+1);

    }
};
