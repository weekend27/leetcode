// Source : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Author : weekend27
// Date   : 2015-12-11

/**********************************************************************************

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

**********************************************************************************/

// How to do it:
// recursively find the root(mid node)
// for example: inorder [4251637], postorder[4526731], first find the root:1, then do it recursively in the left part and right part.

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
    unordered_map<int, int> m;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty())
            return NULL;

        for (int i = 0; i < inorder.size(); i++)
            m[inorder[i]] = i;

        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    TreeNode* build(vector<int>& inorder, int s0, int e0, vector<int>& postorder, int s1, int e1){
        if (s0 > e0 || s1 > e1)
            return NULL;

        TreeNode* root = new TreeNode(postorder[e1]);
        int mid = m[postorder[e1]];
        int num = mid - s0;

        root->left = build(inorder, s0, mid - 1, postorder, s1, s1 + num - 1);
        root->right = build(inorder, mid + 1, e0, postorder, s1 + num, e1 - 1);

        return root;
    }
};
