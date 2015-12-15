// Source : https://leetcode.com/problems/maximum-gap/
// Author : weekend27
// Date   : 2015-12-15

/**********************************************************************************

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

**********************************************************************************/

// How to do it:
// first sort, time O(log(n)), then compare the successive elements
// time over O(n)
// i will make it better in the future



class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int maximum = 0;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] - nums[i-1] > maximum){
                maximum = nums[i] - nums[i-1];
            }
        }
        return maximum;
    }
};
