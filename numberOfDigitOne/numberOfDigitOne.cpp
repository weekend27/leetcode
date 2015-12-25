// Source : https://leetcode.com/problems/number-of-digit-one/
// Author : weekend27
// Date   : 2015-12-25

/**********************************************************************************

Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

Hint:

Beware of overflow.

**********************************************************************************/

// How to do it:
// ref: http://www.cnblogs.com/grandyang/p/4629032.html


class Solution {
public:
    int countDigitOne(int n) {
        int res = 0, a = 1, b = 1;
        while (n > 0){
            res += (n + 8) / 10 * a + (n % 10 == 1) * b;
            b += n % 10 * a;
            a *= 10;
            n /= 10;
        }
        return res;
    }
};
