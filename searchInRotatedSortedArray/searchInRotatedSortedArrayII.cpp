// Source : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Author : weekend27
// Date   : 2015-11-19

/**********************************************************************************

Follow up for "Search in Rotated Sorted Array":

What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

**********************************************************************************/

// How to do it:
// in the search-in-rotated-sorted-array-ii, if nums[m] >= nums[l], [l, m] is not certainly an increasing sequence.
// if nums[m] >= nums[l] can not make sure increasement, the break it into two situations:
// (1) if nums[m] > nums[l], then [l, m] is surely increase.
// (2) if nums[m] == nums[l], then nothing is made sure, so l++, skip it.

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();

        if (len == 0) return false;
        if (len == 1) return (nums[0] == target) ? true : false;

        int low = 0, high = len - 1;

        while (low <= high){
            // no match
            if (nums[low] < nums[high] && (target < nums[low] || target > nums[high])){
                return false;
            }

            // remove duplicates
            while (low < high && nums[low] == nums[high]){
                low++;
            }

            int mid = low + (high - low) / 2;

            // match
            if (nums[mid] == target){
                return true;
            }

            // the target in the non-rotated array
            if (nums[low] < nums[mid] && target >= nums[low] && target < nums[mid]){
                high = mid - 1;
                continue;
            }

            // the target in the non-rotated array
            if (nums[mid] < nums[high] && target > nums[mid] && target <= nums[high]){
                low = mid + 1;
                continue;
            }

            // the target in the rotated array
            // example:
            // array:[4,5,6,7,0,1,1,2,3]   target:7
            if (nums[low] > nums[mid]){
                high = mid - 1;
                continue;
            }

            // the target in the rotated array
            // example:
            // array:[4,5,6,7,0,1,2]   target:1
            if (nums[mid] > nums[high]){
                low = mid + 1;
                continue;
            }

            // reach here means nothing found
            low++;
        }
        return false;
    }
};
