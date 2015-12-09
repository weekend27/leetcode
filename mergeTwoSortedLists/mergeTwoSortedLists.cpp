// Source : https://leetcode.com/problems/merge-two-sorted-lists/
// Author : weekend27
// Date   : 2015-12-09

/**********************************************************************************

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

**********************************************************************************/

// How to do it:
// compare two values, put the smaller one to dummy, and then move to the next node

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* p = &dummy;

        while (l1 && l2){
            int val1 = l1->val;
            int val2 = l2->val;
            // compare two values, put the smaller one to dummy, and then move to the next node
            if (val1 < val2){
                p->next = l1;
                p = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
        }

        // some nodes that are not processed
        if (l1){
            p->next = l1;
        } else if (l2){
            p->next = l2;
        }

        return dummy.next;
    }
};
