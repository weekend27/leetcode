// Source : https://leetcode.com/problems/integer-to-roman/
// Author : weekend27
// Date   : 20156-04-26

/**********************************************************************************

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

**********************************************************************************/

public class Solution {
    public String intToRoman(int num) {
        String[] M = {"", "M", "MM", "MMM"};
        String[] C = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        String[] X = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        String[] I = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        StringBuilder ret = new StringBuilder();
        ret.append(M[num/1000]);
        ret.append(C[(num%1000)/100]);
        ret.append(X[(num%100)/10]);
        ret.append(I[num%10]);

        return ret.toString();
    }

}
