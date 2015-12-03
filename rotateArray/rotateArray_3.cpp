// Source : https://leetcode.com/problems/rotate-array/
// Author : weekend27
// Date   : 2015-12-02

/**********************************************************************************

Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

**********************************************************************************/


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // time O(n)
        int len = nums.size();
        if (k == 0)
            return;
        k = k % len;
        vector<int> numsCopy(len);
        for (int i = 0; i < len; i++)
            numsCopy[i] = nums[i];

        for (int i = 0; i < len; i++)
            nums[(i+k)%len] = numsCopy[i];
    }
};
