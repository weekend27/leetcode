// Source : https://leetcode.com/problems/excel-sheet-column-title/
// Author : weekend27
// Date   : 2015-12-25

/**********************************************************************************

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB

**********************************************************************************/

// How to do it:
// ref: http://yucoding.blogspot.jp/2015/06/leetcode-question-excel-sheet-column.html

class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while (n > 0){
            if (n % 26 == 0){
                res = 'Z' + res;
                n = n / 26 - 1;
            }
            else{
                res = char(n%26 - 1 + 'A') + res;
                n /= 26;
            }
        }
        return res;
    }
};
