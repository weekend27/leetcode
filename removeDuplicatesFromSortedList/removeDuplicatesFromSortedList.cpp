// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Author : weekend27
// Date   : 2015-12-09

/**********************************************************************************

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

**********************************************************************************/

// How to do it:
// two pointers, one follows another, if vals are equal, skip it.
// p->next = p->next->next;

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head){
            return head;
        }

        int val = head->val;
        ListNode* p = head;
        while (p && p->next){
            if (p->next->val != val){
                val = p->next->val;
                p = p->next;
            } else {
                // delete next
                ListNode* n = p->next->next;
                p->next = n;
            }
        }
        return head;
    }
};
