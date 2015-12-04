// Source : https://leetcode.com/problems/4sum/
// Author : weekend27
// Date   : 2015-12-04

/**********************************************************************************

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)

**********************************************************************************/

// How to do it:
// first sort
// fix the smallest two index i and j, and then move l and r to meet together
// remember to remove duplicate quadruplets


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<vector<int>> ret;
        if (len < 4)
            return ret;
            
        sort(nums.begin(), nums.end());
        vector<int> mid(4);
        set<string> isExit;
        for (int i = 0; i < len - 3; i++){
            mid[0] = nums[i];
            for (int j = i + 1; j < len - 2; j++){
                mid[1] = nums[j];
                int l = j + 1;
                int r = len - 1;
                int sum = target - nums[i] - nums[j];
                while (l < r){
                    int tmp = nums[l] + nums[r];
                    if (sum == tmp){
                        string str;
                        str += nums[i];
                        str += nums[j];
                        str += nums[l];
                        str += nums[r];
                        set<string>::iterator itr = isExit.find(str);
                        if (itr == isExit.end()){
                            isExit.insert(str);
                            mid[2] = nums[l];
                            mid[3] = nums[r];
                            ret.push_back(mid);
                        }
                        ++l;
                        --r;
                    }
                    else if(sum > tmp)
                        ++l;
                    else
                        --r;
                }
            }
        }
        
        return ret;
    }
};