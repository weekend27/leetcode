// Source : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
// Author : weekend27
// Date   : 2016-01-16

/**********************************************************************************

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.

**********************************************************************************/

// How to do it:
// binary search
// when nums[mid] == nums[end], exclude nums[end]

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < nums[end]) {
                end = mid;
            }
            else if (nums[mid] > nums[end]) {
                start = mid + 1;
            }
            else {
                end--;
            }
        }
        return nums[start];
    }
};
