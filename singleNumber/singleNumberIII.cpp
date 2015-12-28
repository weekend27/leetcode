// Source : https://leetcode.com/problems/single-number-iii/
// Author : weekend27
// Date   : 2015-12-28

/**********************************************************************************

Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

**********************************************************************************/

// How to do it:
// using sort

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(), nums.end());
        if (nums.size() == 2 && nums[0] != nums[1]){
            return nums;
        }
        for (int i = 0; i < nums.size();){
            if (nums[i] != nums[i+1]){
                res.push_back(nums[i]);
                i++;
            }
            else{
                i += 2;
            }
        }
        return res;
    }
};
