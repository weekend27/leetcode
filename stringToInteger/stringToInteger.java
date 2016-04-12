// Source : https://leetcode.com/problems/string-to-integer-atoi/
// Author : weekend27
// Date   : 2016-04-12

/**********************************************************************************

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.

spoilers alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

**********************************************************************************/

// How to do it:
// note that corner cases:
// 1. whitespaces in the beginning, filter them
// 2. successive '+' or '-', return 0
// 3. out of Integer.MAX_VALUE or Integer.MIN_VALUE

public class Solution {
    public int myAtoi(String str) {

        int len = str.length();

        int i = 0;
        while (i < len && str.charAt(i) == ' ') {  // filter whitespaces
            i++;
        }

        boolean sign = true;
        boolean hasSign = false;
        if (i < len && (str.charAt(i) == '+' || str.charAt(i) == '-')) {
            sign = (str.charAt(i) == '-') ? false : true;
            hasSign = true;
            i++;
        }
        if (hasSign) {
            if (i < len && (str.charAt(i) == '+' || str.charAt(i) == '-')) {   // successive '+' or '-'
                return 0;
            }
        }

        int sum = 0;
        while (i < len && str.charAt(i) >= '0' && str.charAt(i) <= '9') {
            if (sum > Integer.MAX_VALUE / 10 && (str.charAt(i) >= '0' && str.charAt(i) <= '9')) {
                return sign == true ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            } else if (sum == Integer.MAX_VALUE / 10 && (str.charAt(i) >= '0' && str.charAt(i) <= '9')) {
                if (str.charAt(i) >= '7' && sign == true) {
                    return Integer.MAX_VALUE;
                }
                else if (str.charAt(i) >= '8' && sign == false) {
                    return Integer.MIN_VALUE;
                }
                return sign == true ? (sum * 10 + str.charAt(i) - '0') : -(sum * 10 + str.charAt(i) - '0');
            }
            sum = sum * 10 + str.charAt(i) - '0';
            i++;
        }

        return sign == true ? sum : -sum;
    }
}
