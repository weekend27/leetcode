// Source : https://leetcode.com/problems/3sum/
// Author : weekend27
// Date   : 2015-12-03

/**********************************************************************************

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

**********************************************************************************/

// How to do it:
// first sort
// fix the smallest index i, and then move j and k to meet together
// remember to remove duplicates


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> ret;
        int len = nums.size();
        int tar = 0;

        if (len < 3)
            return ret;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < len; ++i){
            // remove duplicates
            if (i != 0 && nums[i] ==nums[i-1])
                continue;

            int j = i + 1;      // the second
            int k = len - 1;    // the third
            int sum = 0;

            // narrow range to find the second and the third element
            while(j < k){
                sum = nums[i] + nums[j] + nums[k];

                if (sum == tar){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    ret.push_back(temp);

                    // remove duplicates
                    while(++j < k && nums[j] == nums[j-1]){
                        //do nothing
                    }
                    while(--k > j && nums[k] == nums[k+1]){
                        //do nothing
                    }
                }
                else if(sum < tar){
                    ++j;
                }
                else{
                    --k;
                }
            }
        }
        return ret;
    }
};
