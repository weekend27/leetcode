// Source : https://leetcode.com/problems/search-for-a-range/
// Author : weekend27
// Date   : 2016-04-06

/**********************************************************************************

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

**********************************************************************************/

// How to do it:
// ref: http://www.programcreek.com/2014/04/leetcode-search-for-a-range-java/
// binarySearch

public class Solution {
    public int[] searchRange(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
            return null;
        }

        int[] array = new int[2];
        array[0] = -1;
        array[1] = -1;

        binarySearch(nums, 0, nums.length - 1, target, array);

        return array;
    }

    public void binarySearch(int[] nums, int left, int right, int target, int[] array){
        if (right < left) {
            return;
        }

        if (nums[left] == nums[right] && nums[left] == target) {
            array[0] = left;
            array[1] = right;
            return;
        }

        int mid = left + (right - left) / 2;

        if (nums[mid] < target) {
            binarySearch(nums, mid+1, right, target, array);
        } else if(nums[mid] > target) {
            binarySearch(nums, left, mid-1, target, array);
        } else {
            array[0] = mid;
            array[1] = mid;

            int l = mid;
            while (l > left && nums[l] == nums[l-1]) {
                l--;
                array[0] = l;
            }

            int r = mid;
            while (r < right && nums[r] == nums[r+1]) {
                r++;
                array[1] = r;
            }

            return;
        }
    }
}
