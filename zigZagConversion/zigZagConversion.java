// Source : https://leetcode.com/problems/zigzag-conversion/
// Author : weekend27
// Date   : 2016-04-12

/**********************************************************************************

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

**********************************************************************************/

// How to do it:
// find the step, and process the zigzag from three parts
// just look at the comments in the code below


public class Solution {
    public String convert(String s, int numRows) {

        if (numRows <= 1) {
            return s;
        }
        StringBuilder result = new StringBuilder();
        int step = numRows * 2 - 2;
        int len = s.length();

        // first row
        for (int i = 0; i < len; i += step) {
            result.append(s.charAt(i));
        }

        // middle zigzag part
        for (int i = 1; i < numRows - 1; ++i) {
            for (int j = i; j < len; j += step) {
                result.append(s.charAt(j));
                if (j + step - 2 * i < len) {
                    result.append(s.charAt(j + step - 2 * i));
                }
            }
        }

        // last row
        for (int i = numRows - 1; i < len; i += step) {
            result.append(s.charAt(i));
        }

        String ret = result.toString();

        return ret;
    }
}
