// Source : https://leetcode.com/problems/remove-element/
// Author : weekend27
// Date   : 2015-12-02

/**********************************************************************************

Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

**********************************************************************************/

// How to do it:
// two pointers

class Solution {
public:
    int removeElement(vector<int>& nums, int val){
        int startPosition = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != val){
                nums[startPosition] = nums[i];
                startPosition++;
            }
        }
        return startPosition;
    }
};
