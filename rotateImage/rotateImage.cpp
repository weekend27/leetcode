// Source : https://leetcode.com/problems/rotate-image/
// Author : weekend27
// Date   : 2015-12-07

/**********************************************************************************

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

**********************************************************************************/

// How to do it:
// use another matrix
// space O(n*n)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> tmp(n, vector<int>(n));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                tmp[i][j] = matrix[i][j];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                matrix[j][n - 1 - i] = tmp[i][j];

    }
};
