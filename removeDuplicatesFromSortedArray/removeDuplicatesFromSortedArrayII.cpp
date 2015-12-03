// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Author : weekend27
// Date   : 2015-11-18

/**********************************************************************************

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

**********************************************************************************/

// How to do it:
// Two pointers: add one variable to record the times that elements appear.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int index = 2;

        if (len <= 2) return len;

        for (int i = 2; i < len; i++){
            if (nums[index-2] != nums[i])
                nums[index++] = nums[i];
        }

        return index;
    }
};
