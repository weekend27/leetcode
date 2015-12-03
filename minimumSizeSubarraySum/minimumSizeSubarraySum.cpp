// Source : https://leetcode.com/problems/minimum-size-subarray-sum/
// Author : weekend27
// Date   : 2015-12-03

/**********************************************************************************

Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

**********************************************************************************/

// How to do it:
// two pointers, sliding window


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        int minLen = len + 1;
        int start = 0, end = 0, sum = 0;
        while(end < len){
            while(sum < s && end < len){
                sum += nums[end];
                end++;
            }

            while(sum >= s && start < len){
                minLen = min(minLen, end-start);
                if (minLen == 1)
                    return minLen;
                sum -= nums[start];
                start++;
            }

            if (sum >= s)
                minLen = min(minLen, end-start);
        }

        return minLen == (len + 1) ? 0 : minLen;
    }
};
