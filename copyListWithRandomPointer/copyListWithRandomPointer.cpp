// Source : https://leetcode.com/problems/copy-list-with-random-pointer/
// Author : weekend27
// Date   : 2015-12-22

/**********************************************************************************

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

**********************************************************************************/

// How to do it:
// ref: http://fisherlei.blogspot.sg/2013/11/leetcode-copy-list-with-random-pointer.html
// 1. insert nodes
// 2. copy random pointer
// 3. decouple two links

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // insert nodes
        RandomListNode* curr = head;
        while (curr != NULL){
            RandomListNode* temp = new RandomListNode(curr->label);
            temp->next = curr->next;
            curr->next = temp;
            curr = temp->next;    // move to next node in the old linked list
        }

        // copy random pointer
        curr = head;
        while (curr != NULL){
            RandomListNode* temp = curr->next;
            if (curr->random != NULL){
                temp->random = curr->random->next;
            }
            curr = temp->next;
        }

        // decouple two links
        curr = head;
        RandomListNode* dup = (head == NULL) ? NULL : head->next;
        while(curr != NULL){
            RandomListNode* temp = curr->next;
            curr->next = temp->next;
            if (temp->next != NULL){
                temp->next = temp->next->next;
            }
            curr = curr->next;
        }

        return dup;
    }
};
