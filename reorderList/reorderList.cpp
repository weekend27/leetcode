// Source : https://leetcode.com/problems/reorder-list/
// Author : weekend27
// Date   : 2015-12-10

/**********************************************************************************

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

**********************************************************************************/

// How to do it:
// fast and slow pointers to cut the list into two parts
// reverse the right part
// merge two parts

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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;

        // fast and slow pointers to cut the list into two parts
        ListNode* fp = head;   // fast pointer
        ListNode* sp = head;

        while (fp->next && fp->next->next){
            fp = fp->next->next;
            sp = sp->next;
        }

        fp = sp->next;
        sp->next =NULL;

        // reverse the right part
        ListNode dummy(0);
        while (fp){
            ListNode* next = dummy.next;
            dummy.next = fp;
            ListNode* nn = fp->next;
            fp->next = next;
            fp = nn;
        }

        sp = head;
        fp = dummy.next;

        // merge by sequence
        while (sp){
            if (fp){
                ListNode* sn = sp->next;
                sp->next = fp;
                ListNode* fn = fp->next;
                fp->next = sn;
                fp = fn;
                sp = sn;
            } else {
                break;
            }
        }

    }
};
