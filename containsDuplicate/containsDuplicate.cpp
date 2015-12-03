// Source : https://leetcode.com/problems/contains-duplicate/
// Author : weekend27
// Date   : 2015-11-27

/**********************************************************************************

Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

**********************************************************************************/

// How to do it:
// two steps: sort the vector first, and then check if the adjacent elements are the same

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) return false;
        vector<int>& array = nums;
        std::sort(array.begin(),array.end());
        for(int i = 1; i < array.size(); i++){
            if (array[i] == array[i-1])  return true;
        }
        return false;
    }
};
