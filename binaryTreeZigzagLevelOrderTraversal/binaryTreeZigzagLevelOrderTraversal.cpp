// Source : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Author : weekend27
// Date   : 2015-12-11

/**********************************************************************************

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

**********************************************************************************/

// How to do it:
// almost the same as https://leetcode.com/problems/binary-tree-level-order-traversal/
// just reverse the every two elements in the values vector



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
vector<vector<int>> values;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        build(root, 0);

        // reverse
        for (int i = 1; i < values.size(); i += 2)
            reverse(values[i].begin(), values[i].end());

        return values;
    }

    void build(TreeNode* node, int level){
        if (!node)
            return;

        if (values.size() <= level)
            values.push_back(vector<int>());        // initialization

        values[level].push_back(node->val);

        if (node->left)
            build(node->left, level + 1);

        if (node->right)
            build(node->right, level + 1);
    }
};
