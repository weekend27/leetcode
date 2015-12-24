// Source : https://leetcode.com/problems/sudoku-solver/
// Author : weekend27
// Date   : 2015-12-24

/**********************************************************************************

Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

**********************************************************************************/

// How to do it:
// look at the code

class Solution {

private:
    int rowValid[9][10];        // rowValid[i][j] means whether number in i-th row j-th col is used or not
    int columnValid[9][10];     // columnValid[i][j] means whether number in i-th col j-th row is used or not
    int subBoardValid[9][10];   // subBoardValid[i][j] means whether number in i-th grid j-th position is used or not

public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] != '.'){
                    fill(i, j, board[i][j] - '0');
                }
            }
        }
        solver(board, 0);
    }

    bool solver(vector<vector<char>> &board, int index){
        // 0 <= index <= 80, index is the index-th grid to fill next
        if (index > 80){
            return true;
        }

        int row = index / 9;
        int col = index - 9 * row;

        if (board[row][col] != '.'){
            return solver(board, index+1);
        }
        for (int val = '1'; val <= '9'; val++){
            // 9 possible numbers to fill
            if (isValid(row, col, val-'0')){
                board[row][col] = val;
                fill(row, col, val-'0');
                if (solver(board, index+1)){
                    return true;
                }
                clear(row, col, val-'0');
            }
        }
        board[row][col] = '.';  // reset board status
        return false;
    }

    // check if it is valid after filling val in [row][col]
    bool isValid(int row, int col, int val){
        if (rowValid[row][val] == 0 &&
            columnValid[col][val] == 0 &&
            subBoardValid[row/3*3+col/3][val] == 0){
                return true;
            }
        return false;
    }

    // update filling status
    void fill(int row, int col, int val){
        rowValid[row][val] = 1;
        columnValid[col][val] = 1;
        subBoardValid[row/3*3+col/3][val] = 1;
    }

    // clear filling status
    void clear(int row, int col, int val){
        rowValid[row][val] = 0;
        columnValid[col][val] = 0;
        subBoardValid[row/3*3+col/3][val] = 0;
    }
};
