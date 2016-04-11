// Source : https://leetcode.com/problems/median-of-two-sorted-arrays/
// Author : weekend27
// Date   : 2016-04-11

/**********************************************************************************

There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

**********************************************************************************/

// How to do it:
// The key point of this problem is to ignore 1/4 part of A and B each step recursively by comparing the median of remaining A and B:
// if (aMid < bMid) Keep [aRight + b]
// else Keep [bRight + a]


public class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int len1 = nums1.length;
        int len2 = nums2.length;
        int l = (len1 + len2 + 1) >> 1;
        int r = (len1 + len2 + 2) >> 1;
        return (getkth(nums1, 0, nums2, 0, l) + getkth(nums1, 0, nums2, 0, r)) / 2.0;
    }

    private int getkth(int[] A, int aStart, int[] B, int bStart, int k) {
        if (aStart > A.length - 1) return B[bStart + k - 1];
        if (bStart > B.length - 1) return A[aStart + k - 1];
        if (k == 1) return Math.min(A[aStart], B[bStart]);

        int aMid = Integer.MAX_VALUE, bMid = Integer.MAX_VALUE;
        if (aStart + k/2 - 1 < A.length) aMid = A[aStart + k/2 - 1];
        if (bStart + k/2 - 1 < B.length) bMid = B[bStart + k/2 - 1];

        if (aMid < bMid)
            return getkth(A, aStart + k/2, B, bStart, k - k/2);  // Check: aRight + bLeft
        else
            return getkth(A, aStart, B, bStart + k/2, k - k/2);  // Check: bRight + aLeft
    }
}
