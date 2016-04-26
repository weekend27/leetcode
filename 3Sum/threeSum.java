// Source : https://leetcode.com/problems/3sum/
// Author : weekend27
// Date   : 2016-04-26

/**********************************************************************************

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

**********************************************************************************/

// How to do it:
// first sort
// fix the smallest index i, and then move j and k to meet together
// remember to remove duplicates
/*
注意的点：
（1）i的去重，不可以用while循环判断，也不能写成i++;
错误的写法：
if (i > 0 && nums[i] == nums[i-1]) i++;
while (i > 0 && nums[i] == nums[i-1]) continue;
（2）sum == target时，不能忘记j++;k--这两步。
*/

public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        if (nums == null || nums.length < 3) return result;

        int len = nums.length;
        int target = 0;

        Arrays.sort(nums);

        for (int i = 0; i < len - 2; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;          // skip the same elements
            int j = i + 1, k = len - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    result.add(Arrays.asList(nums[i], nums[j], nums[k]));
                    while (j < k && nums[j] == nums[j+1]) j++;    // skip the same elements
                    while (j < k && nums[k] == nums[k-1]) k--;    // skip the same elements
                    j++;
                    k--;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        return result;
    }
}
