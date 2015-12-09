// Source : https://leetcode.com/problems/linked-list-cycle-ii/
// Author : weekend27
// Date   : 2015-12-09

/**********************************************************************************

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?

**********************************************************************************/

// How to do it:
// two poiters go, one fast, the other slow, if they meet some time, the list has cycle.
// when they meet, let the slow one go back to head, and meet again.
// the analysis is here:https://siddontang.gitbooks.io/leetcode-solution/content/linked_list/linked_list_cycle.html

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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL){
            return NULL;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        while (fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
