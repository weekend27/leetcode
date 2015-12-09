// Source : https://leetcode.com/problems/linked-list-cycle/
// Author : weekend27
// Date   : 2015-12-09

/**********************************************************************************

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

**********************************************************************************/

// How to do it:
// two poiters go, one fast, the other slow, if they meet some time, the list has cycle.

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
    bool hasCycle(ListNode *head) {
        // two pointers go ahead, one fast, the other slow, if they meet some time, then the list has cycle
        if(head == NULL || head->next == NULL){
            return false;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast){
                return true;
            }
        }

        return false;
    }
};
