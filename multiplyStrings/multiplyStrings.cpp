// Source : https://leetcode.com/problems/multiply-strings/
// Author : weekend27
// Date   : 2015-12-17

/**********************************************************************************

Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.

**********************************************************************************/

// How to do it:
// ref: http://bangbingsyb.blogspot.jp/2014/11/leetcode-multiply-strings.html


class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty()){
            return "";
        }
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string ret(num1.size() + num2.size(), '0');

        for (int j = 0; j < num2.size(); j++){
            int carry = 0;
            int val = num2[j] - '0';
            for (int i = 0; i < num1.size(); i++){
                carry += ((num1[i] - '0') * val + (ret[i+j] - '0'));
                ret[i+j] = carry % 10 + '0';
                carry /= 10;
            }
            if (carry != 0){
                ret[num1.size() + j] = carry + '0';
            }
        }
        reverse(ret.begin(), ret.end());

        int cnt = 0;
        while (cnt < ret.size() - 1 && ret[cnt] == '0'){
            cnt++;
        }
        ret.erase(0, cnt);
        return ret;
    }
};
