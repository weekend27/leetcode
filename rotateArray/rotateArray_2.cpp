// Source : https://leetcode.com/problems/rotate-array/
// Author : weekend27
// Date   : 2015-12-02

/**********************************************************************************

Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

**********************************************************************************/

// How to do it:
// three reverses:(1)the whole; (2)the front part; (3)the end part.

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};
