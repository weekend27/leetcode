// Source : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Author : weekend27
// Date   : 2015-12-11

/**********************************************************************************

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

**********************************************************************************/

// How to do it:
// recursively find the root(mid node)
// for example: inorder [4251637], preorder[1234567], first find the root:1, then do it recursively in the left part and right part.


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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())
            return NULL;

        for (int i = 0; i < inorder.size(); i++)
            m[inorder[i]] = i;

        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, int s0, int e0, vector<int>& inorder, int s1, int e1){
        if (s0 > e0 || s1 > e1)
            return NULL;

        int mid = m[preorder[s0]];

        TreeNode* root = new TreeNode(preorder[s0]);

        int num = mid - s1;

        root->left = build(preorder, s0 + 1, s0 + num, inorder, s1, mid - 1);
        root->right = build(preorder, s0 + num + 1, e0, inorder, mid + 1, e1);

        return root;
    }
};
