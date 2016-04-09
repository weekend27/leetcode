// Source : https://leetcode.com/problems/jump-game/
// Author : weekend27
// Date   : 2016-04-09

/**********************************************************************************

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

**********************************************************************************/

// How to do it:
// ref: https://leetcode.com/discuss/11422/simplest-o-n-solution-with-constant-space
// Idea is to work backwards from the last index. Keep track of the smallest index that can "jump" to the last index.
// Check whether the current index can jump to this smallest index.

public class Solution {
    public boolean canJump(int[] nums) {
        int n = nums.length;
        int last = n - 1;
        int i, j;
        for (i = n - 2; i >= 0; i--) {
            if (i + nums[i] >= last) last = i;
        }
        return last <= 0;
    }
}
