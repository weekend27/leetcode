// Source : https://leetcode.com/problems/valid-parentheses/
// Author : weekend27
// Date   : 2015-12-16

/**********************************************************************************

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

**********************************************************************************/

// How to do it:
// use a stack to map

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        if (s.size() == 0){
            return false;
        }
        stack.push_back(s[0]);
        for (int i = 1; i < s.size(); i++){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
                stack.push_back(s[i]);
                continue;
            }
            char curr = stack.back();
            if (s[i] == ')' && curr != '('){
                return false;
            }
            if (s[i] == ']' && curr != '['){
                return false;
            }
            if (s[i] == '}' && curr != '{'){
                return false;
            }
            stack.pop_back();
        }
        if (stack.size() != 0){
            return false;
        }
        return true;
    }
};
