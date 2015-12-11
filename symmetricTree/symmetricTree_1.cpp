// Source : https://leetcode.com/problems/symmetric-tree/
// Author : weekend27
// Date   : 2015-12-11

/**********************************************************************************

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

**********************************************************************************/

// How to do it:
// 3 features:
// 1. left->val == right->val
// 2. left->left, right->right
// 3. left->right, right->left
// for iteration version, we use two queues to store infomation of left and right trees

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
    bool isSymmetric(TreeNode* root) {
        // iteration
        if (root == NULL)
            return true;

        TreeNode* n1 = root->left;
        TreeNode* n2 = root->right;
        if (!n1 && !n2)
            return true;
        if ((!n1 && n2) || (n1 && !n2))
            return false;

        queue<TreeNode*> Q1;
        queue<TreeNode*> Q2;
        Q1.push(n1);
        Q2.push(n2);

        while(!Q1.empty() && !Q2.empty())
        {
            TreeNode* temp1 = Q1.front();
            TreeNode* temp2 = Q2.front();
            Q1.pop();
            Q2.pop();
            if ((!temp1 && temp2) || (temp1 && !temp2))
                return false;
            if (temp1 && temp2){
                if (temp1->val != temp2->val)
                    return false;
                Q1.push(temp1->left);
                Q1.push(temp1->right);
                Q2.push(temp2->right); // note: we should put the mirror sequence into Q2
                Q2.push(temp2->left);
            }
        }

        return true;
    }
};
