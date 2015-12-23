// Source : https://leetcode.com/problems/valid-sudoku/
// Author : weekend27
// Date   : 2015-12-23

/**********************************************************************************

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

**********************************************************************************/

// How to do it:
// deal with every row, every col, every 9-grid box

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++){
            set<char> s; // check every col
            for (int j = 0; j < 9; j++)
                if(board[i][j] == '.')
                    continue;
                else if(s.find(board[i][j]) != s.end())
                    return false;
                else
                    s.insert(board[i][j]);

            s.clear(); // check every row
            for (int j = 0; j < 9; j++)
                if(board[j][i] == '.')
                    continue;
                else if(s.find(board[j][i]) != s.end())
                    return false;
                else
                    s.insert(board[j][i]);

            s.clear(); // check every box
            int x = i/3*3, y = i%3*3;
            for (int j = x; j < x+3; j++)
                for (int k = y; k < y+3; k++)
                    if(board[j][k] == '.')
                        continue;
                    else if(s.find(board[j][k]) != s.end())
                        return false;
                    else
                        s.insert(board[j][k]);
        }
        return true;
    }
};
