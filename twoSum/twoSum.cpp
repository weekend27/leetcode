// Source : https://leetcode.com/problems/two-sum/
// Author : weekend27
// Date   : 2015-12-03

/**********************************************************************************

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

**********************************************************************************/

// How to do it:
// two steps:
// (1) two pointers from the start and the end to match the target, and then break
// (2) traverse the original array to find the two index

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v(nums);
        sort(v.begin(), v.end());

        int l = 0, r = v.size() - 1;
        while(l < r){
            if (v[l] + v[r] == target)
                break;
            else if (v[l] + v[r] > target)
                r--;
            else
                l++;
        }

        vector<int> index;
        for (int i = 0, n = 2; i < nums.size(); i++){
            if(v[l] == nums[i] || v[r] == nums[i]){
                index.push_back(i + 1);
                if(--n == 0)
                    break;
            }
        }
        return index;
    }
};
