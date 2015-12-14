// Source : https://leetcode.com/problems/sum-root-to-leaf-numbers/
// Author : weekend27
// Date   : 2015-12-14

/**********************************************************************************

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

**********************************************************************************/

// How to do it:
// DFS
// vec change to num


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
    int sumNumbers(TreeNode* root) {
        vector<int> arr;
        int sum = 0;
        dfs(root, arr, sum);
        return sum;
    }

    int vec2num(vector<int>& vec){
        int num = 0;
        for (auto n : vec){
            num = num * 10 + n;
        }
        return num;
    }

    void dfs(TreeNode* node, vector<int>&arr, int& sum){
        if (node == nullptr)
            return;
            arr.push_back(node->val);
            if (node->left == nullptr && node->right == nullptr){
                sum += vec2num(arr);
            } else {
                if (node->left != nullptr) dfs(node->left, arr, sum);
                if (node->right != nullptr) dfs(node->right, arr, sum);
            }
            arr.pop_back();
    }
};
