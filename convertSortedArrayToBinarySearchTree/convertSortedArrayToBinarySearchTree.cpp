// Source : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Author : weekend27
// Date   : 2015-12-14

/**********************************************************************************

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

**********************************************************************************/

// How to do it:
// find the mid element, left part is left sub-tree, right part is right sub-tree, and then divide and conquer


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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size());
    }

    TreeNode* build(vector<int>& nums, int begin, int end){
        if (begin >= end)
            return NULL;

        int mid = begin + (end - begin) / 2;

        TreeNode* node = new TreeNode(nums[mid]);
        node->left = build(nums, begin, mid);
        node->right = build(nums, mid+1, end);

        return node;
    }
};
