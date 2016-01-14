// Source : https://leetcode.com/problems/power-of-three/
// Author : weekend27
// Date   : 2016-01-14

/**********************************************************************************

Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?

**********************************************************************************/

// How to do it:
// just look at code, while loop

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};
