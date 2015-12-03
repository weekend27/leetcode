// Source : https://leetcode.com/problems/move-zeroes/
// Author : weekend27
// Date   : 2015-12-02

/**********************************************************************************

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

**********************************************************************************/

// How to do it:
// Two pointers,
// Traversal, when it meets zero, move left, and put the zero element to the end.
// At the same time, narrow the range.
// Don't remember to i--.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if(nums[i] == 0){
                for (int j = i; j < n - 1; j++){
                    nums[j] = nums[j+1];
                }
                nums[n-1] = 0;
                n--;
                i--;
            }
        }
    }
};
