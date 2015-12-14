// Source : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Author : weekend27
// Date   : 2015-12-14

/**********************************************************************************

Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

**********************************************************************************/

// How to do it:
// ref: https://siddontang.gitbooks.io/leetcode-solution/content/tree/populating_next_right_pointers_in_each_node.html
/*
这题需要在一棵完全二叉树中使用next指针连接旁边的节点，我们可以发现一些规律。

如果一个子节点是根节点的左子树，那么它的next就是该根节点的右子树，譬如上面例子中的4，它的next就是2的右子树5。
如果一个子节点是根节点的右子树，那么它的next就是该根节点next节点的左子树。譬如上面的5，它的next就是2的next（也就是3）的左子树。
*/



/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root)
            return;

        TreeLinkNode* n = root;
        TreeLinkNode* first = NULL;
        while (n){
            // record the first left sub-tree in the next down level
            if (!first){
                first = n->left;
            }
            // if there is a left sub-tree, then next is right sub-tree
            if (n->left){
                n->left->next = n->right;
            }
            else {   // leaf nodes, travesal over
                break;
            }

            // if next exists, then set up right sub-tree's next
            if (n->next){
                n->right->next = n->next->left;
                n = n->next;
                continue;
            } else {
                // turn to next level
                n = first;
                first = NULL;
            }

        }
    }
};
