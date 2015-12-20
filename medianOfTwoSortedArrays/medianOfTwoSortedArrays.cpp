// Source : https://leetcode.com/problems/median-of-two-sorted-arrays/
// Author : weekend27
// Date   : 2015-12-20

/**********************************************************************************

There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

**********************************************************************************/

// How to do it:
// merge
// time complexity: O(m+n)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int pa = 0, pb = 0;
        vector<int> tmp;

        while (pa < len1 || pb < len2){
            if (pa == len1){
                tmp.push_back(nums2[pb++]);
                continue;
            }
            if (pb == len2){
                tmp.push_back(nums1[pa++]);
                continue;
            }
            if (nums1[pa] > nums2[pb]){
                tmp.push_back(nums2[pb++]);
            }
            else{
                tmp.push_back(nums1[pa++]);
            }
        }

        int len = tmp.size();
        if (len % 2 == 1){
            return tmp[len/2];
        }
        else {
            return (tmp[len/2] + tmp[len/2 - 1]) / 2.0;
        }
    }
};
