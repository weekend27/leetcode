// Source : https://leetcode.com/problems/unique-paths/
// Author : weekend27
// Date   : 2015-12-03

/**********************************************************************************

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

**********************************************************************************/

// How to do it:
// dynamic programming


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> v(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                v[i][j] = v[i-1][j] + v[i][j-1];

        return v[m-1][n-1];
    }
};
