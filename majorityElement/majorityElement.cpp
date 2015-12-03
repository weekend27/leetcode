// Source : https://leetcode.com/problems/majority-element/
// Author : weekend27
// Date   : 2015-12-03

/**********************************************************************************

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

**********************************************************************************/

// How to do it:
// when you find two different elements, delete them together.
// http://www.cnblogs.com/ganganloveu/p/4177690.html



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++){
            if (count == 0){
                candidate = nums[i];
                count = 1;
            }else{
                if (nums[i] == candidate){
                    count++;
                }else{
                    count--;
                }
            }
        }
        return candidate;
    }
};
