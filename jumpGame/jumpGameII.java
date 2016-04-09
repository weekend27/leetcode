// Source : https://leetcode.com/problems/jump-game-ii/
// Author : weekend27
// Date   : 2016-04-09

/**********************************************************************************

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.

**********************************************************************************/

// How to do it:
// ref: http://www.programcreek.com/2014/06/leetcode-jump-game-ii-java/
// This is an extension of Jump Game. The solution is similar, but we also track the maximum steps of last jump.

public class Solution {
    public int jump(int[] nums) {
        if (nums == null || nums.length == 0) {
            return -1;
        }

        int lastReach = 0;
        int reach = 0;
        int step = 0;

        for (int i = 0; i <= reach && i < nums.length; ++i) {
            // when last jump can not read current i, increase the step by 1
            if (i > lastReach) {
                step++;
                lastReach = reach;
            }
            // update the max jump
            reach = Math.max(reach, nums[i] + i);
        }

        if (reach < nums.length - 1) {
            return -1;
        }

        return step;
    }
}
