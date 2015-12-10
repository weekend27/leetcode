// Source : https://leetcode.com/problems/sort-list/
// Author : weekend27
// Date   : 2015-12-10

/**********************************************************************************

Sort a linked list in O(n log n) time using constant space complexity.

**********************************************************************************/

// How to do it:
// divide and conquer, make the problem smaller


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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL){
            return head;
        }

        ListNode* fp = head;  // fast pointer
        ListNode* sp = head;  // slow pointer

        // get the mid point of the linked list
        while (fp->next && fp->next->next){
            fp = fp->next->next;
            sp = sp->next;
        }

        // break the list up into two parts
        fp = sp->next;
        sp->next = NULL;

        // sort in the left and right part
        ListNode* p1 = sortList(head);
        ListNode* p2 = sortList(fp);

        // merge
        return merge(p1, p2);
    }

    ListNode* merge(ListNode* l1, ListNode* l2){
        if (!l1)
            return l2;
        else if (!l2)
            return l1;
        else if (!l1 && !l2)
            return NULL;

        ListNode dummy(0);
        ListNode* p = &dummy;

        while (l1 && l2){
            if (l1->val < l2->val){
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }

            p = p->next;
        }

            if (l1)
                p->next = l1;
            else if (l2)
                p->next = l2;

            return dummy.next;
    }
};
