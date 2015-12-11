// Source : https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
// Author : weekend27
// Date   : 2015-12-11

/**********************************************************************************

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

**********************************************************************************/

// How to do it:
// almost the same as https://leetcode.com/problems/binary-tree-level-order-traversal/
// the only difference is: the sequence that we put the elements into result-vector


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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int depth = height(root);
        vector<vector<int>> ret(depth);
        if (depth == 0)
            return ret;
        DFS(ret, ret.size() - 1, root);
        return ret;
    }

    int height(TreeNode* root){
        if (root == NULL)
            return 0;

        int lh = height(root->left);
        int rh = height(root->right);
        int height = (lh > rh ? lh : rh) + 1;
        return height;
    }

    void DFS(vector<vector<int>>& ret, int level, TreeNode* root){
        if (root == NULL)
            return;
        ret[level].push_back(root->val);
        DFS(ret, level-1, root->left);
        DFS(ret, level-1, root->right);
    }
};
