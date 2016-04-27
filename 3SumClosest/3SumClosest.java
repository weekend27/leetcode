// Source : https://leetcode.com/problems/3sum-closest/
// Author : weekend27
// Date   : 2016-04-27

/**********************************************************************************

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

**********************************************************************************/

// How to do it:
// three pointers like 3Sum

public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        if (nums == null || nums.length < 3) return 0;

        int len = nums.length;
        int diff = 0;
        int res = 0;
        int minDiff = Integer.MAX_VALUE;
        Arrays.sort(nums);

        for (int i = 0; i < len - 2; ++i) {
            int j = i + 1;
            int k = len - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return target;
                } else {
                    diff = Math.abs(sum - target);
                    if (diff < minDiff) {
                        minDiff = diff;
                        res = sum;
                    }

                    if (sum < target) {
                        j++;
                    } else {
                        k--;
                    }
                }
            }
        }

        return res;
    }
}
