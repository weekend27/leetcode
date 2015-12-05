// Source : https://leetcode.com/problems/sort-colors/
// Author : weekend27
// Date   : 2015-12-05

/**********************************************************************************

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?

**********************************************************************************/

// How to do it:
// just do it as "Follow up"
// a low algorithom


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cntRed = 0;
        int cntWhite = 0;
        int cntBlue = 0;

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0)
                cntRed++;
            else if (nums[i] == 1)
                cntWhite++;
            else
                cntBlue++;
        }

        for (int i = 0; i < cntRed; i++)
            nums[i] = 0;
        for (int i = cntRed; i < cntRed + cntWhite; i++)
            nums[i] = 1;
        for (int i = cntRed + cntWhite; i < nums.size(); i++)
            nums[i] = 2;
    }
};
