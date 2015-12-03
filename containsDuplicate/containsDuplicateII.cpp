// Source : https://leetcode.com/problems/contains-duplicate-ii/
// Author : weekend27
// Date   : 2015-12-03

/**********************************************************************************

Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array
such that nums[i] = nums[j] and the difference between i and j is at most k.

**********************************************************************************/

// How to do it:
// hash table

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> int_map;
        map<int, int>::iterator iter;
        for (int i = 0; i < nums.size(); i++){
            if((iter = int_map.find(nums[i])) != int_map.end()){
                if (i - iter->second <= k)
                    return true;
                else
                    int_map.erase(iter);
            }
            int_map.insert(pair<int, int>(nums[i], i));
        }
        return false;
    }
};
