// Source : https://leetcode.com/problems/roman-to-integer/
// Author : weekend27
// Date   : 2016-04-26

/**********************************************************************************

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

**********************************************************************************/

// How to do it:
// ref: http://blog.csdn.net/wzy_1988/article/details/17057929
/*
计数规则：
1. 相同的数字连写，所表示的数等于这些数字相加得到的数，例如：III = 3
2. 小的数字在大的数字右边，所表示的数等于这些数字相加得到的数，例如：VIII = 8
3. 小的数字，限于（I、X和C）在大的数字左边，所表示的数等于大数减去小数所得的数，例如：IV = 4
4. 正常使用时，连续的数字重复不得超过三次
5. 在一个数的上面画横线，表示这个数扩大1000倍（本题只考虑3999以内的数，所以用不到这条规则）
*/
// 从前向后遍历罗马数字，如果某个数比前一个数小，则加上该数。反之，减去前一个数的两倍然后加上该数，这里有个处理的细节需要注意：之前已经加了前一个数，所以现在不需要加上了。

public class Solution {
    public int romanToInt(String s) {
        int result = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (i > 0 && c2n(s.charAt(i)) > c2n(s.charAt(i-1))) {
                // trick here!
                // we should add (c2n(s[i]) - 2 * c2n(s[i-1]) + c2n(s[i-1])) here.
                // but we have added c2n(s[i-1]) in the prev loop, so watch out here.
                result += c2n(s.charAt(i)) - 2 * c2n(s.charAt(i-1));
            } else {
                // handle the following conditions:
                // (1) the 0-index
                // (2) the current number <= the prev number
                result += c2n(s.charAt(i));
            }
        }
        return result;
    }

    public static int c2n(char c) {
        switch(c) {
            case('I'): return 1;
            case('V'): return 5;
            case('X'): return 10;
            case('L'): return 50;
            case('C'): return 100;
            case('D'): return 500;
            case('M'): return 1000;
            default  : return 0;
        }
    }
}
