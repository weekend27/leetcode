// Source : https://leetcode.com/problems/divide-two-integers/
// Author : weekend27
// Date   : 2016-04-06

/**********************************************************************************

Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

**********************************************************************************/

// How to do it:
// ref: http://www.programcreek.com/2014/05/leetcode-divide-two-integers-java/
/*
This problem can be solved based on the fact that any number can be converted to the format of the following:

num=a_0*2^0+a_1*2^1+a_2*2^2+...+a_n*2^n
*/


public class diviTwoIntegers {
    public int divide(int dividend, int divisor) {
        // handle special cases
        if (divisor == 0) return Integer.MAX_VALUE;
        if (divisor == -1 && dividend == Integer.MIN_VALUE) return Integer.MAX_VALUE;

        // get positive values
        long pDividend = Math.abs((long)dividend);
        long pDivisor = Math.abs((long)divisor);

        int result = 0;
        while (pDividend >= pDivisor) {
            // calculate number of left shifts
            int numShift = 0;
            while (pDividend >= (pDivisor << numShift)) {
                numShift++;
            }

            // dividend minus the largest shifted divisor
            result += 1 << (numShift - 1);
            pDividend -= (pDivisor << (numShift - 1));
        }

        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
            return result;
        } else {
            return -result;
        }

    }
}
