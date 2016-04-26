// Source : https://leetcode.com/problems/container-with-most-water/
// Author : weekend27
// Date   : 2016-04-26

/**********************************************************************************

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

**********************************************************************************/

// How to do it:
// 所谓求容积也就是求面积，长方形面积 = 长 * 宽，所以可以让left = 0, right = height.length - 1，向中间靠拢；
// 在寻找下一个长方形时，移动高度较小的下标即可
// 时间复杂度： O(n)

public class Solution {
    public int maxArea(int[] height) {
        int maxArea = 0, area;
        int left = 0, right = height.length - 1;
        while (left < right) {
            area = (right - left) * min(height[left], height[right]);
            maxArea = (maxArea > area) ? maxArea : area;
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return maxArea;
    }

    public static int min(int a, int b) {
        return (a < b) ? a : b;
    }
}
