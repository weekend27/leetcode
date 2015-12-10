// Source : https://leetcode.com/problems/swap-nodes-in-pairs/
// Author : weekend27
// Date   : 2015-12-10

/**********************************************************************************

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

**********************************************************************************/

// How to do it:
// a pointer problem
// swap two adjacent nodes and then move on

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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next){
            return head;
        }

        ListNode* p = new ListNode(0);
        p->next = head;
        head = p;
        while(true){
            if (p->next == NULL) {break;}
            if (p->next->next == NULL) {break;}
            ListNode* p1 = p->next;
            ListNode* p2 = p1->next;
            p1->next = p2->next;
            p2->next = p1;
            p->next = p2;
            p = p1;
        }
        return head->next;
    }
};
