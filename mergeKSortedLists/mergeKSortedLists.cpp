// Source : https://leetcode.com/problems/merge-k-sorted-lists/
// Author : weekend27
// Date   : 2015-12-09

/**********************************************************************************

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

**********************************************************************************/

// How to do it:
// divide and conquer, make the problem smaller
// time complexity: Nlog(N)


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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()){
            return NULL;
        }

        // divide and conquer
        int n = lists.size();
        while (n > 1){
            int k = (n + 1) / 2;
            for (int i = 0; i < n / 2; i++){
                // merge i and i+k lists, and put merged one in the i position
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            // in the next loop, you just need to process k lists
            n = k;
        }
        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
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

        if (l1){
            p->next = l1;
        } else if (l2){
            p->next = l2;
        }

        return dummy.next;
    }
};
