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
// compare from the end to the start, and then put the larger one to the array nums1
// time O(n+m)


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int index = m + n -1;
        int index1 = m - 1;
        int index2 = n - 1;
        while(0 <= index1 && 0 <= index2){  // two vectors traverse not done
            if(nums2[index2] > nums1[index1])
                nums1[index--] = nums2[index2--];
            else
                nums1[index--] = nums1[index1--];
        }
        while(0 <= index1){ //only vector nums1 traverse not done
            nums1[index--] = nums1[index1--];
        }
        while(0 <= index2){ //only vector nums2 traverse not done
            nums1[index--] = nums2[index2--];
        }
    }

};
