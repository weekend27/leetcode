// Source : https://leetcode.com/problems/pascals-triangle/
// Author : weekend27
// Date   : 2015-12-02

/**********************************************************************************

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

**********************************************************************************/

// How to do it:
// add every vector sequently

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> rVec;
        for (int i = 0; i < numRows; i++){
            vector<int> cur;
            if (i == 0)     // initial assignment
                cur.push_back(1);
            else{
                for (int j = 0; j <= i; j++){
                    if (j == 0 || j == i)   // the left and right boundaries
                        cur.push_back(1);
                    else
                        cur.push_back(rVec[i-1][j] + rVec[i-1][j-1]);  // normal situation
                }
            }
            rVec.push_back(cur);
        }

        return rVec;
    }
};
