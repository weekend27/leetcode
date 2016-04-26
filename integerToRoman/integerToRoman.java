// Source : https://leetcode.com/problems/integer-to-roman/
// Author : weekend27
// Date   : 20156-04-26

/**********************************************************************************

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

**********************************************************************************/


public class Solution {
    public String intToRoman(int num) {
        String[][] roman = {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM"}
        };

        StringBuilder ret = new StringBuilder();
        int digit = 0;
        while (num > 0) {
            int remain = num % 10;      // remain part
            ret = ret.insert(0, roman[digit][remain]);      // insert the remain part in the 0 index
            digit++;
            num /= 10;
        }
        String result = ret.toString();
        return result;
    }

}
