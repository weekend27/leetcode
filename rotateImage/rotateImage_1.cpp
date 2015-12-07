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
// the piece of paper folded up and down along
// and then fold diagonally

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int tmp;

        // the piece of paper folded up and down along
        for (int i = 0; i < n / 2; i++){
            for (int j = 0; j < n; j++){
                tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-i][j];
                matrix[n-1-i][j] = tmp;
            }
        }

        // and then fold diagonally
        for (int i = 0; i < n; i++){
            for (int j = 0; j < i; j++){
                tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }

    }
};
