// Source : https://leetcode.com/problems/invert-binary-tree/
// Author : weekend27
// Date   : 2015-12-28

/**********************************************************************************

Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.

**********************************************************************************/

// How to do it:
// use a queue to do BFS

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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr){
            return root;
        }

        queue<TreeNode*> myQueue;   // use a queue to do BFS
        myQueue.push(root);

        while (!myQueue.empty()){
            TreeNode* node = myQueue.front();
            myQueue.pop();

            if (node->left != nullptr){
                myQueue.push(node->left);
            }

            if (node->right != nullptr){
                myQueue.push(node->right);
            }

            // invert left and right pointers
            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;
        }

        return root;
    }
};
