// Source : https://leetcode.com/problems/factorial-trailing-zeroes/
// Author : weekend27
// Date   : 2015-12-25

/**********************************************************************************

Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

**********************************************************************************/

// How to do it:
// ref: https://leetcode.com/discuss/20691/my-explanation-of-the-log-n-solution


class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        while(n > 0){
            cnt += n/5;
            n /= 5;
        }
        return cnt;
    }
};
