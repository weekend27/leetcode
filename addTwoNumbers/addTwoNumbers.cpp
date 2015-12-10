// Source : https://leetcode.com/problems/add-two-numbers/
// Author : weekend27
// Date   : 2015-12-10

/**********************************************************************************

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

**********************************************************************************/

// How to do it:
// easy! add two numbers one by one
// please note the carry


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* p = &dummy;

        int carry = 0;

        while (l1 || l2){
            int val = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            carry = val / 10;
            val = val % 10;
            p->next = new ListNode(val);
            p = p->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        if (carry != 0){
            p->next = new ListNode(carry);
            p = p->next;
        }

        return dummy.next;
    }
};
