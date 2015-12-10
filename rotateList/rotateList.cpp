// Source : https://leetcode.com/problems/rotate-list/
// Author : weekend27
// Date   : 2015-12-10

/**********************************************************************************

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

**********************************************************************************/

// How to do it:
// connect the head and the tail to a loop
// find the break-point position
// break up and return


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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0)
            return head;

        // get the len of list
        int len = 1;
        ListNode* p = head;
        while(p->next){
            p = p->next;
            len++;
        }

        k = len - k % len;

        // connect the head and the tail to a loop
        p->next = head;

        for (int i = 0; i < k; i++){
            p = p->next;
        }

        // get new head and break up the loop
        head = p->next;
        p->next = NULL;
        return head;
    }
};
