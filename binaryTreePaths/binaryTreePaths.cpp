// Source : https://leetcode.com/problems/binary-tree-paths/
// Author : weekend27
// Date   : 2015-12-14

/**********************************************************************************

Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]

**********************************************************************************/

// How to do it:
// DFS



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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root == nullptr)
            return result;

        vector<int> path;
        DFS(root, path, result);
        return result;
    }

    void DFS(TreeNode* node, vector<int>& path, vector<string>& result){
        if (node == nullptr)
            return;
        path.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr)
            result.push_back(generatePath(path));
        else{
            if (node->left != nullptr){
                DFS(node->left, path, result);
                path.pop_back();
            }
            if (node->right != nullptr){
                DFS(node->right, path, result);
                path.pop_back();
            }
        }
    }

    string generatePath(vector<int> path){
        stringstream ss;
        int i;
        for (i = 0; i < path.size() - 1; i++)
            ss << path[i] << "->";
        ss << path[i];
        return ss.str();
    }
};
