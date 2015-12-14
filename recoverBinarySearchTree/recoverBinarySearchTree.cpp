// Source : https://leetcode.com/problems/recover-binary-search-tree/
// Author : weekend27
// Date   : 2015-12-14

/**********************************************************************************

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

**********************************************************************************/

// How to do it:
// InOrderTraversal
// space O(n)


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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> list;
        vector<int> values;
        InOrderTraversal(root, list, values);
        sort(values.begin(), values.end());
        for (int i = 0; i < list.size(); i++)
            list[i]->val = values[i];
    }

    void InOrderTraversal(TreeNode* node, vector<TreeNode*>& list, vector<int>& values){
        if (node == NULL)
            return;
        InOrderTraversal(node->left, list, values);
        list.push_back(node);
        values.push_back(node->val);
        InOrderTraversal(node->right, list, values);
    }
};
