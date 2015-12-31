// Source : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Author : weekend27
// Date   : 2015-12-31

/**********************************************************************************

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

**********************************************************************************/

// How to do it:
// ref: http://fisherlei.blogspot.jp/2012/12/leetcode-remove-nth-node-from-end-of.html
// 经典题。双指针，一个指针先走n步，然后两个同步走，直到第一个走到终点，第二个指针就是需要删除的节点。唯一要注意的就是头节点的处理，比如，1->2->NULL, n =2; 这时，要删除的就是头节点。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        assert(head);
        ListNode* pre;
        ListNode* cur;
        pre = head;
        cur = head;
        int step = 0;
        while (step < n && cur != NULL){
            cur = cur->next;
            step++;
        }
        if (step == n && cur == NULL){
            head = head->next;
            delete pre;
            return head;
        }
        while (cur->next != NULL){
            pre = pre->next;
            cur = cur->next;
        }
        ListNode* tmp = pre->next;
        pre->next = tmp->next;
        delete tmp;
        return head;
    }
};
