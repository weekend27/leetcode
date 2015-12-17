// Source : https://leetcode.com/problems/roman-to-integer/
// Author : weekend27
// Date   : 2015-12-17

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


class Solution {
public:
    inline int c2n(char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default : return 0;
        }
    }
    int romanToInt(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++){
            if (i > 0 && c2n(s[i]) > c2n(s[i-1])){
                result += (c2n(s[i]) - 2*c2n(s[i-1]));
            }
            else {
                result += c2n(s[i]);
            }
        }
        return result;
    }
};
