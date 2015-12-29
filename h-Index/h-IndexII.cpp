// Source : https://leetcode.com/problems/h-index-ii/
// Author : weekend27
// Date   : 2015-12-29

/**********************************************************************************

Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?

Hint:

Expected runtime complexity is in O(log n) and the input is sorted.

**********************************************************************************/

// How to do it:
// binary search


class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n - 1;
        while (l <= r){
            int m = l + (r - l) / 2;
            if (citations[m] < n - m){
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return n - l;
    }
};
