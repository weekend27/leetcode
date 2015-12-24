// Source : https://leetcode.com/problems/ugly-number/
// Author : weekend27
// Date   : 2015-12-24

/**********************************************************************************

Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.

**********************************************************************************/

// How to do it:
// look at the code


class Solution {
public:
    bool isUgly(int num) {
        while (num >= 2){
            if (num % 2 == 0){
                num /= 2;
            }
            else if (num % 3 == 0){
                num /= 3;
            }
            else if (num % 5 == 0){
                num /= 5;
            }
            else {
                return false;
            }
        }
        return num == 1;
    }
};
