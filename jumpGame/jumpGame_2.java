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
// ref: http://www.programcreek.com/2014/03/leetcode-jump-game-java/
/* We can track the maximum index that can be reached. The key to solve this problem is to find:
 * 1) when the current position can not reach next position (return false) ,
 * 2) when the maximum index can reach the end (return true).
 * The largest index that can be reached is: i + A[i].
*/

public class Solution {
    public boolean canJump(int[] nums) {
        if (nums.length < 2) {
            return true;
        }

        int max = nums[0];  // max stands for the largest index that can be reached

        for (int i = 0; i < nums.length - 1; ++i) {
            // if not enough to go to next
            if (max <= i && nums[i] == 0) {
                return false;
            }

            // update max
            if (i + nums[i] > max) {
                max = i + nums[i];
            }

            // max is enough to go to the end
            if (max >= nums.length - 1) {
                return true;
            }
        }

        return false;
    }
}
