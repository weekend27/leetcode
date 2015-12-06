// Source : https://leetcode.com/problems/search-insert-position/
// Author : weekend27
// Date   : 2015-12-06

/**********************************************************************************

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

**********************************************************************************/

// How to do it:
// binary search

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0)
            return 0;

        int l = 0, r = n - 1, m = 0;
        while (l <= r){
            m = l + (r - l) / 2;
            if (nums[m] == target)
                return m;
            else if (nums[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }

    }
};
