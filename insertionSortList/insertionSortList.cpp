// Source : https://leetcode.com/problems/sort-list/
// Author : weekend27
// Date   : 2015-12-10

/**********************************************************************************



**********************************************************************************/

// How to do it:
// insertion sort
// for the n+1 node, just traverse the previous n nodes and put it in the proper position


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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode dummy(0);
        ListNode* p = &dummy;
        ListNode* curr = head;
        while (curr){
            p = &dummy;
            while (p->next && p->next->val <= curr->val)
                p = p->next;

            ListNode* next = p->next;
            p->next = curr;
            curr = curr->next;
            p->next->next = next;
        }

        return dummy.next;
    }
};
