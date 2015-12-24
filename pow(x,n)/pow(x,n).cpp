// Source : https://leetcode.com/problems/powx-n/
// Author : weekend27
// Date   : 2015-12-24

/**********************************************************************************

Implement pow(x, n).

**********************************************************************************/

// How to do it:
// ref: divide and conquer

class Solution {
public:
    double power(double x, int n) {
        if (n == 0)
        {
            return 1;
        }

        double v = power(x, n/2);
        if (n % 2 == 0)
        {
            return v * v;
        }
        else
        {
            return v * v * x;
        }
    }

    double myPow(double x, int n) {
        if (n < 0)
        {
            return 1.0 / power(x, -n);
        }
        else
        {
            return power(x, n);
        }
    }
};
