// Source : https://leetcode.com/problems/sqrtx/
// Author : weekend27
// Date   : 2015-12-24

/**********************************************************************************

Implement int sqrt(int x).

Compute and return the square root of x.

**********************************************************************************/

// How to do it:
// binary search
// note that the final return number

class Solution {
public:
    int mySqrt(int x) {
        long long l = 0;
        long long r = x / 2 + 1;
        while (l <= r)
        {
            long long mid = l + (r - l) / 2;
            long long sq = mid * mid;
            if (sq == x)
            {
                return mid;
            }
            else if (sq < x)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return r;
    }
};
