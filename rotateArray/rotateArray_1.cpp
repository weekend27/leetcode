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
// use two arrays to put the elements from two parts, and then put them back to the original array.
// space O(n)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;
        if(k == 0)
            return;
        vector<int> p, q;
        for (int i = 0; i < len - k; i++)
            p.push_back(nums[i]);
        for (int i = len - k; i < len; i++)
            q.push_back(nums[i]);
        for (int i = 0; i < k; i++)
            nums[i] = q[i];
        for (int i = k; i < len; i++)
            nums[i] = p[i-k];
    }
};
