// Source : https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
// Author : weekend27
// Date   : 2015-12-14

/**********************************************************************************

Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

**********************************************************************************/

// How to do it:
// ref: https://siddontang.gitbooks.io/leetcode-solution/content/tree/populating_next_right_pointers_in_each_node.html
/*
不同于上一题，这题的二叉树并不是完全二叉树，我们不光需要提供first指针用来表示一层的第一个元素，
同时也需要使用另一个lst指针表示该层上一次遍历的元素。那么我们只需要处理好如何设置last的next指针就可以了。
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
        TreeLinkNode* last = NULL;

        while (n){
            // set up the next level first element
            if (!first){
                if (n->left){
                    first = n->left;
                } else if (n->right){
                    first = n->right;
                }
            }

            if (n->left){
                // if last exists, set up last's next
                if (last)
                    last->next = n->left;

                // last is left
                last = n->left;
            }

            if (n->right){
                // if last exists, set up last's next
                if (last)
                    last->next = n->right;

                // last is right
                last = n->right;
            }

            // if next exists, go to next
            if (n->next){
                n = n->next;
            } else {
                // go to next level
                n = first;
                last = NULL;
                first = NULL;
            }
        }
    }
};
