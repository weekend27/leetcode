// Source : https://leetcode.com/problems/minimum-depth-of-binary-tree/
// Author : weekend27
// Date   : 2015-12-10

/**********************************************************************************

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

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
    int n;
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;

        // initialize n to be max
        n = numeric_limits<int>::max();
        int d = 1;

        depth(root, d);
        return n;
    }

    void depth(TreeNode* node, int& d){
        // leaf node, compare
        if (!node->left && !node->right){
            n = min(n, d);
            return;
        }

        if (node->left){
            d++;
            depth(node->left, d);
            d--;
        }

        if (node->right){
            d++;
            depth(node->right, d);
            d--;
        }
    }
};
