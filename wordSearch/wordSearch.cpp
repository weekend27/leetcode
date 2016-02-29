// Source : https://leetcode.com/problems/word-search/
// Author : weekend27
// Date   : 2016-01-10

/**********************************************************************************

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

**********************************************************************************/

// How to do it :
// ref: http://bangbingsyb.blogspot.jp/2014/11/leetcode-word-search.html
/*
以board上的每个cell为出发点，利用depth first search向上下左右四个方向搜索匹配word。
搜索的时候要考虑board的边界，cell是否已经在DFS的路径上被用过，以及cell上的值是否与word的当前字符匹配。
为了跟踪DFS的路径避免同一个cell被访问多次，使用一个visited矩阵来代表board上任意的cell(i, j)是否已经被访问过。
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) {
            return false;
        }

        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (findWord(board, visited, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool findWord(vector<vector<char>> &board, vector<vector<bool>> &visited, int row, int col, string &word, int index) {
        if (index == word.size()) {
            return true;
        }

        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || visited[row][col] || board[row][col] != word[index]) {
            return false;
        }

        visited[row][col] = true;
        if (findWord(board, visited, row-1, col, word, index+1)) {return true;}
        if (findWord(board, visited, row, col+1, word, index+1)) {return true;}
        if (findWord(board, visited, row+1, col, word, index+1)) {return true;}
        if (findWord(board, visited, row, col-1, word, index+1)) {return true;}
        visited[row][col] = false;
        return false;
    }
};
