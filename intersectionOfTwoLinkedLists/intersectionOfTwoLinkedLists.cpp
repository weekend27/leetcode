// Source : https://leetcode.com/problems/intersection-of-two-linked-lists/
// Author : weekend27
// Date   : 2015-12-09

/**********************************************************************************

Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

**********************************************************************************/

// How to do it:
// traverse A, in the tail of A, link the tail to B
// two pointers fast and slow to check if there is a cycle
// if no cycle, break up two lists before return
// if cycle, ref linkedListCycle/linkedListCycleII.cpp to find the start, and then break up two lists before return


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA){
            return NULL;
        } else if (!headB){
            return NULL;
        }

        ListNode* p = headA;
        while (p->next){
            p = p->next;
        }

        // concatenate two lists
        p->next = headB;

        ListNode* tail = p;
        p = headA;

        // fast and slow to check whether there is a cycle
        headB = headA;
        while (headB->next && headB->next->next){
            headA = headA->next;
            headB = headB->next->next;
            if (headA == headB){
                break;
            }
        }

        if (!headA->next || !headB->next || !headB->next->next){
            // no loop, break up two lists
            tail->next = NULL;
            return NULL;
        }

        // loop, get the start of the loop
        headA = p;
        while (headA != headB){
            headA = headA->next;
            headB = headB->next;
        }

        // break up two lists
        tail->next = NULL;
        return headA;
    }
};
