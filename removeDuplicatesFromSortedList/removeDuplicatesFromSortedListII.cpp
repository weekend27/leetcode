// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// Author : weekend27
// Date   : 2015-12-09

/**********************************************************************************

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

**********************************************************************************/

// How to do it:
// add another ListNode dummy to be head->prev

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

        // add another ListNode dummy to be head->prev
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* p = head;
        while (p && p->next){
            // no replicates
            if (p->val != p->next->val){
                prev = p;
                p = p->next;
            } else {
                // replicates, still traverse until meeting no replicates
                int val = p->val;
                ListNode* n = p->next->next;
                while(n){
                    if(n->val != val){
                        break;
                    }else{
                        n = n->next;
                    }
                }
                // remove duplicates
                prev->next = n;
                p = n;
            }
        }
        return dummy.next;  // you can not return head;
    }
};
