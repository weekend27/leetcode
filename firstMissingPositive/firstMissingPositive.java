// Source : https://leetcode.com/problems/first-missing-positive/
// Author : weekend27
// Date   : 2016-04-07

/**********************************************************************************

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

**********************************************************************************/

// How to do it:
// ref: https://leetcode.com/discuss/28531/o-1-space-java-solution
// ref: http://blog.csdn.net/kenden23/article/details/17099987
// ref: http://www.cnblogs.com/AnnieKim/archive/2013/04/21/3034631.html

public class Solution {
    public int firstMissingPositive(int[] nums) {
        int i = 0;
        while (i < nums.length) {
            if (nums[i] <= 0 || nums[i] > nums.length || nums[i] == i+1) {
                i++;
            } else if (nums[nums[i]-1] != nums[i]) {
                swap(nums, nums[i]-1, i);
            } else {
                i++;
            }
        }
        i = 0;
        while (i < nums.length && nums[i] == i+1) {
            i++;
        }
        return i+1;
    }

    private void swap(int[] nums, int i, int j) {
        nums[i] = nums[i] ^ nums[j];
        nums[j] = nums[i] ^ nums[j];
        nums[i] = nums[i] ^ nums[j];
    }
}
