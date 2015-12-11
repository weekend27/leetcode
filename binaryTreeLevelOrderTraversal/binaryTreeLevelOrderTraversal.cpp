// Source : https://leetcode.com/problems/binary-tree-level-order-traversal/
// Author : weekend27
// Date   : 2015-12-11

/**********************************************************************************

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".

**********************************************************************************/

// How to do it:
// first construct the ret vector, so we need to know the depth of this tree
// get height of tree
// put nodes into the vector

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
/* we neet to first construct the ret vector, so we need to know the depth of this tree */
    vector<vector<int>> levelOrder(TreeNode* root) {
        int depth = getHeight(root);
        vector<vector<int>> ret(depth);
        if (depth == 0)
            return ret;
        getVector(ret, root, 0);
        return ret;
    }

    int getHeight(TreeNode* root){
        // for this question, empth tree height : 0, only one node tree height : 1
        if (root == NULL)
            return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        int height = (left > right ? left : right) + 1;
        return height;
    }

    void getVector(vector<vector<int>>& ret, TreeNode* root, int level){
        if (root == NULL)
            return;
        ret[level].push_back(root->val);
        getVector(ret, root->left, level+1);
        getVector(ret, root->right, level+1);
    }
};
