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
// recursion



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
        // recursion
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* p = head->next;
        ListNode* n = reverseList(p);

        head->next = NULL;
        p->next = head;
        return n;
    }
};
