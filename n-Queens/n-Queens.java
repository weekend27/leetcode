// Source : https://leetcode.com/problems/n-queens/
// Author : weekend27
// Date   : 2016-04-07

/**********************************************************************************

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

**********************************************************************************/

// How to do it:
// ref: https://leetcode.com/discuss/60250/java-clean-accepted-solution-92-3%25


public class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> list = new ArrayList<List<String>>();
        dfs(new int[n], 0, n, list);
        return list;
    }

    private void dfs(int[] pos, int step, int n, List<List<String>> list) {
        if (step == n) {
            ArrayList<String> ls = printboard(pos, n);
            list.add(new ArrayList<String>(ls));
            return;
        }
        for (int i = 0; i < n; i++) {
            pos[step] = i;
            if (isValid(pos, step)) {
                dfs(pos, step+1, n, list);
            }
        }
    }

    private boolean isValid(int[] pos, int step) {
        for (int i = 0; i < step; i++) {
            if (pos[i] == pos[step] || (Math.abs(pos[i]-pos[step])) == (step-i)) {
                return false;
            }
        }
        return true;
    }

    private ArrayList<String> printboard(int[] pos, int n) {
        ArrayList<String> ls = new ArrayList<String>();
        for (int i = 0; i < n; i++) {
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < n-1; j++) sb.append('.');
            sb.insert(pos[i], 'Q');
            ls.add(sb.toString());
        }
        return ls;
    }
}
