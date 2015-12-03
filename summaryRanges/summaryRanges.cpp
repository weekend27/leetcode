// Source : https://leetcode.com/problems/summary-ranges/
// Author : weekend27
// Date   : 2015-12-02

/**********************************************************************************

Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

**********************************************************************************/

// How to do it:
// two pointers

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums){
        vector<string> srVec;
        if (nums.size()<1)
            return srVec;
        int start = 0;
        int end = 0;
        char temp[256];
        while (end < nums.size()){
            if (end + 1 < nums.size() && nums[end+1] == nums[end]+1){
                end++;
            } else{
                if (start == end){
                    sprintf(temp, "%d", nums[start]);
                } else{
                    sprintf(temp, "%d->%d", nums[start], nums[end]);
                }
                srVec.push_back(temp);
                end++;
                start = end;
            }
        }
        return srVec;
    }

};
