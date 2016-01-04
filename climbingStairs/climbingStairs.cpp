// Source : https://leetcode.com/problems/climbing-stairs/
// Author : weekend27
// Date   : 2016-01-02

/**********************************************************************************

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

**********************************************************************************/

// How to do it:
// recursion, dynamic

class Solution {
public:
    int climbStairs(int n) {
        vector<int> res(n+1);
        res[0] = 1;
        res[1] = 1;
        for (int i = 2; i <= n; i++) {
            res[i] = res[i-1] + res[i-2];
        }
        return res[n];
    }
};