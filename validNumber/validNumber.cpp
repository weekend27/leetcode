// Source : https://leetcode.com/problems/valid-number/
// Author : weekend27
// Date   : 2015-12-18

/**********************************************************************************

Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.

**********************************************************************************/

// How to do it:
// ref: http://www.jiuzhang.com/solutions/valid-number/


class Solution {
public:
    bool isNumber(string s) {
        int len = s.length();
        int i = 0, e = len - 1;
        while (i <= e && s[i] == ' '){  // delete whitespaces in the beginning
            i++;
        }
        while (e >= i && s[e] == ' '){  // delete whitespaces in the end
            e--;
        }
        if (s[i] == '+' || s[i] == '-'){
            i++;
        }
        bool num = false;   // is a digit
        bool dot = false;   // is a '.'
        bool exp = false;   // is a 'e'
        while (i <= e){
            char c = s[i];
            if (isDigit(c)){
                num = true;
            }
            else if (c == '.'){
                if (exp || dot){
                    return false;
                }
                dot = true;
            }
            else if (c == 'e'){
                if (exp || num == false){
                    return false;
                }
                exp = true;
                num = false;    // important! reset num to false!
            }
            else if (c == '+' || c == '-'){
                if (s[i-1] != 'e'){
                    return false;
                }
            }
            else {
                return false;
            }
            i++;
        }
        return num;
    }

    bool isDigit(char c){
        if (c >= '0' && c <= '9'){
            return true;
        }
        return false;
    }
};
