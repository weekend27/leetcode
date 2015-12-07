// Source : https://leetcode.com/problems/reverse-linked-list/
// Author : weekend27
// Date   : 2015-12-07

/**********************************************************************************

Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?

**********************************************************************************/

// How to do it:
// iteration


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
    ListNode* reverseList(ListNode* head) {
        // iteration
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* pre = head;
        ListNode* next = head->next;
        ListNode* nextnext = head->next->next;
        pre->next = NULL;
        while(next){
            nextnext = next->next;
            next->next = pre;
            pre = next;
            next = nextnext;
        }
        return pre;
    }
};
