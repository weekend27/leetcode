// Source : https://leetcode.com/problems/search-in-rotated-sorted-array/
// Author : weekend27
// Date   : 2015-11-19

/**********************************************************************************

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

**********************************************************************************/

// How to do it:
// binary search, the difficulty is determining the left and right boundaries.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int low = 0, high = len;

        while(low != high){  // error:low <= high, example:[1] search:0 wrong answer:0 expected answer:-1
            const int mid = low + (high - low) / 2;  // mid = (low + high) / 2 may encounter overflow
            if (nums[mid] == target)
                return mid;
            if (nums[low] <= nums[mid]){
                if (nums[low] <= target && target < nums[mid]){
                    high = mid;
                }
                else{
                    low = mid + 1;
                }
            }
            else{
                if (nums[mid] < target && target <= nums[high - 1]){  // error:nums[high]
                    low = mid + 1;
                }
                else{
                    high = mid;
                }
            }
        }
        return -1;
    }
};
