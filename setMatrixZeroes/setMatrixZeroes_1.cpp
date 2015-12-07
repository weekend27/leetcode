// Source : https://leetcode.com/problems/set-matrix-zeroes/
// Author : weekend27
// Date   : 2015-12-07

/**********************************************************************************

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

**********************************************************************************/

// How to do it:
// use another array to record the zero position
// and then set the original row and col to zero
// space O(m+n)


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 0)
            return;
        int col = matrix[0].size();
        if (col == 0)
            return;

        bool* flag = new bool[row+col];
        memset(flag, false, row+col);

        // record the zero position
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (matrix[i][j] == 0){
                    flag[i] = 1;
                    flag[row+j] = 1;
                }
            }
        }

        // set the col to zero
        for (int i = 0; i < row; i++){
            if (flag[i]){
                for (int j = 0; j < col; j++)
                    matrix[i][j] = 0;
            }
        }

        // set the row to zero
        for (int j = row; j < row+col; j++){
            if (flag[j]){
                for (int i = 0; i < row; i++)
                    matrix[i][j-row] = 0;
            }
        }


    }
};
