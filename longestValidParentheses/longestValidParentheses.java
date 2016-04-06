// Source : https://leetcode.com/problems/longest-valid-parentheses/
// Author : weekend27
// Date   : 2016-04-06

/**********************************************************************************

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

**********************************************************************************/

// How to do it:
// ref: http://www.programcreek.com/2014/06/leetcode-longest-valid-parentheses-java/

public class Solution {
    public int longestValidParentheses(String s) {
        Stack<int[]> stack = new Stack<int[]>();
        int result = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(') {
                int[] a = {i, 0};
                stack.push(a);
            } else {
                if (stack.empty() || stack.peek()[1] == 1) {
                    int[] a = {i, 1};
                    stack.push(a);
                } else {
                    stack.pop();
                    int currentLen = 0;
                    if (stack.empty()) {
                        currentLen = i + 1;
                    } else {
                        currentLen = i - stack.peek()[0];
                    }
                    result = Math.max(result, currentLen);
                }
            }
        }

        return result;
    }
}
