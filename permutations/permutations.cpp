// Source : https://leetcode.com/problems/permutations/
// Author : weekend27
// Date   : 2015-12-30

/**********************************************************************************

Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

**********************************************************************************/

// How to do it:
// ref: http://bangbingsyb.blogspot.jp/2014/11/leetcode-permutations-i-ii.html
// insert method


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> allPer;
        if (nums.empty()){
            return allPer;
        }
        allPer.push_back(vector<int>(1, nums[0]));

        for (int i = 1; i < nums.size(); i++){
            int n = allPer.size();
            for (int j = 0; j < n; j++){
                for (int k = 0; k < allPer[j].size(); k++){
                    vector<int> per = allPer[j];
                    per.insert(per.begin() + k, nums[i]);
                    allPer.push_back(per);
                }
                allPer[j].push_back(nums[i]);
            }
        }
        return allPer;
    }
};
