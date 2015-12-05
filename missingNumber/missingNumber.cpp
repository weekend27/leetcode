// Source : https://leetcode.com/problems/missing-number/
// Author : weekend27
// Date   : 2015-12-06

/**********************************************************************************

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

**********************************************************************************/

// How to do it:
// use the arithmetic sequence to sum up the array, and then minus the elements to find the missing one.

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expect = (n + 1) * n / 2;
        for (int i = 0; i < n; i++)
            expect -= nums[i];
        return expect;
    }
};
