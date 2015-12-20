// Source : https://leetcode.com/problems/kth-largest-element-in-an-array/
// Author : weekend27
// Date   : 2015-12-20

/**********************************************************************************

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.

**********************************************************************************/

// How to do it:
// sort, find the one by index

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        return nums[N - k];
    }
};
