// Source : https://leetcode.com/problems/basic-calculator/
// Author : weekend27
// Date   : 2015-12-19

/**********************************************************************************

Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.

**********************************************************************************/

// How to do it:
// use two stacks to store numbers and signs


class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<int> signs;
        int num = 0, res = 0, sign = 1;
        for (auto ch : s){
            if (ch == ' '){
                continue;
            }
            if (isdigit(ch)){
                num = num * 10 + (ch - '0');
            }
            else {
                res += num * sign;
                num = 0;
                if (ch == '+'){
                    sign = 1;
                }
                if (ch == '-'){
                    sign = -1;
                }
                if (ch == '('){
                    nums.push(res);
                    signs.push(sign);
                    res = 0;
                    sign = 1;
                }
                if (ch == ')'){
                    res = nums.top() + res * signs.top();
                    nums.pop();
                    signs.pop();
                }
            }
        }
        res += sign * num;
        return res;

    }
};
