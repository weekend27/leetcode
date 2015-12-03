// Source : https://leetcode.com/problems/merge-sorted-array/
// Author : weekend27
// Date   : 2015-12-02

/**********************************************************************************

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
The number of elements initialized in nums1 and nums2 are m and n respectively.

**********************************************************************************/

// How to do it:
// move nums1[0~m-1] to nums1[n~n+m-1], merge nums1 and nums2 to nums1
// time O(n+m)


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        // move nums1[0~m-1] to nums1[n~n+m-1]
        for (int i = m - 1; i >= 0; i--)
            nums1[n + i] = nums1[i];

        // merge
        int pa = n, pb = 0, cnt = 0;
        while (pa < n + m && pb < n){
            if (nums1[pa] < nums2[pb])
                nums1[cnt++] = nums1[pa++];
            else
                nums1[cnt++] = nums2[pb++];
        }
        while (pb < n)
            nums1[cnt++] = nums2[pb++];
    }
};
