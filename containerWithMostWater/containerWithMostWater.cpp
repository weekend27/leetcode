// Source : https://leetcode.com/problems/container-with-most-water/
// Author : weekend27
// Date   : 2016-01-05

/**********************************************************************************

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

**********************************************************************************/

// How to do it:
// ref: http://blog.csdn.net/wzy_1988/article/details/17248209

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i, j, lh, rh, area, temp;
        int len = height.size();

        lh = height[0];
        rh = height[len-1];
        area = 0;
        i = 0;
        j = len - 1;

        while (i < j) {
            temp = (lh < rh ? lh : rh) * (j - i);

            if (temp > area) {
                area = temp;
            }

            if (lh < rh) {
                while (i < j && height[i] <= lh) {
                    i++;
                }
                if (i < j) {
                    lh = height[i];
                }
            } else {
                while (i < j && height[j] <= rh) {
                    j--;
                }
                if (i < j){
                    rh = height[j];
                }
            }
        }

        return area;
    }
};
