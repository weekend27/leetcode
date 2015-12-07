// Source : https://leetcode.com/problems/set-matrix-zeroes/
// Author : weekend27
// Date   : 2015-12-07

/**********************************************************************************

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

**********************************************************************************/

// How to do it:
// record whether first row and first col has zero
// find the zero elements and make the elements in the first row and first col zero
// find the zero elements in the first row and the first col, and then make the whole row and col zero
// make the first row and first col zero
// space O(1)


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 0) return;
        int col = matrix[0].size();
        if (col == 0) return;

        // record whether first row and first col has zero
        bool firstRowIsZero = false;
        bool firstColIsZero = false;

        for (int j = 0; j < col; j++){
            if (matrix[0][j] == 0){
                firstRowIsZero = true;
                break;
            }
        }

        for (int i = 0; i < row; i++){
            if (matrix[i][0] == 0){
                firstColIsZero = true;
                break;
            }
        }

        // find the zero elements and make the elements in the first row and first col zero
        for (int i = 1; i < row; i++){
            for (int j = 1; j < col; j++){
                if (matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // find the zero element in the first row and the first col, and then make the whole row and col zero
        for (int i = 1; i < row; i++){
            if (matrix[i][0] == 0){
                for (int j = 1; j < col; j++)
                    matrix[i][j] = 0;
            }
        }

        for (int j = 1; j < col; j++){
            if (matrix[0][j] == 0){
                for (int i = 1; i < row; i++)
                    matrix[i][j] = 0;
            }
        }

        // make the first row and first col zero
        if (firstRowIsZero){
            for (int j = 0; j < col; j++)
                matrix[0][j] = 0;
        }

        if (firstColIsZero){
            for (int i = 0; i < row; i++)
                matrix[i][0] = 0;
        }


    }
};
