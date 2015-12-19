// Source : https://leetcode.com/problems/trapping-rain-water/
// Author : weekend27
// Date   : 2015-12-19

/**********************************************************************************

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

**********************************************************************************/

// How to do it:
// ref: comments from 李瑞远 on http://fisherlei.blogspot.sg/2013/01/leetcode-trapping-rain-water.html

class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if (len < 3){
            return 0;
        }
        int start = 0, end = len - 1;
        int result = 0, minH = 0;

        minH = min(height[start], height[end]);
        result = minH * (end - start - 1);

        while (start < end - 1){
            if (height[start] < height[end]){
                start++;
                result = result - min(minH, height[start]);
            }
            else {
                end--;
                result = result - min(minH, height[end]);
            }
            if (height[start] > minH && height[end] > minH){
                result += min(height[start] - minH, height[end] - minH) * (end -start - 1); // add overflow part
                minH = min(height[start], height[end]);
            }
        }
        return result;
    }
};
