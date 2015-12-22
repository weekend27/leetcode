// Source : https://leetcode.com/problems/single-number/
// Author : weekend27
// Date   : 2015-12-22

/**********************************************************************************

Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

**********************************************************************************/

// How to do it:
// ref: http://bangbingsyb.blogspot.sg/2014/11/leetcode-single-number-i-ii.html
/*
和find duplicate正好相反，但是仍然可以用排序或hash table解决。排序以后，对每个坐标i，查找A[i-1], A[i+1]中是否有等于A[i]的，没有则为要找的数。
或者用hash table/set来记录扫描过的数字。如果A[i]不在hash table中，则插入，如果已经在，则在hash table中删除，最后table中剩下的就是要找的数。
但排序法事件复杂度是O(nlogn)，而hash table尽管是O(n)事件复杂度，需要o(n)的extra memory。

这题的终极解法是利用位运算中的异或：x^x = 0, x^0 = x。并且异或有交换律：1^1^0 = 0 = 1^0^1。
所以如果将全部数字进行异或运算，所有重复元素都会被消除，最后的结果便是那个唯一的数。
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++){
            res ^= nums[i];
        }
        return res;
    }
};
