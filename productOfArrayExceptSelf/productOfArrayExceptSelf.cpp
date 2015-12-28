// Source : https://leetcode.com/problems/product-of-array-except-self/
// Author : weekend27
// Date   : 2015-12-28

/**********************************************************************************

Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

**********************************************************************************/

// How to do it:
// ref: https://leetcode.com/discuss/46104/simple-java-solution-in-o-n-without-extra-space
// two traverses

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prod(n, 1);
        for (int i = 1; i < n; i++){
            prod[i] = prod[i - 1] * nums[i - 1];
        }
        for (int i = n - 1, r = 1; i >= 0; r *= nums[i--]){
            prod[i] *= r;
        }
        return prod;
    }
};
