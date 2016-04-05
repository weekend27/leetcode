// Source : https://leetcode.com/problems/regular-expression-matching/
// Author : weekend27
// Date   : 2016-04-05

/**********************************************************************************

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

**********************************************************************************/

// How to do it:
// ref: http://www.programcreek.com/2012/12/leetcode-regular-expression-matching-in-java/
/*
First of all, this is one of the most difficulty problems. It is hard to think through all different cases. The problem should be simplified to handle 2 basic cases:
the second char of pattern is "*"
the second char of pattern is not "*"
For the 1st case, if the first char of pattern is not ".", the first char of pattern and string should be the same. Then continue to match the remaining part.

For the 2nd case, if the first char of pattern is "." or first char of pattern == the first i char of string, continue to match the remaining part.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


public class regularExpressionMatching {
    public boolean isMatch(String s, String p) {
        if (p.length() == 0) {
            return s.length() == 0;
        }

        if (p.length() == 1 || p.charAt(1) != '*') {
            if (s.length() < 1 || (p.charAt(0) != '.' && s.charAt(0) != p.charAt(0)))
                return false;
            return isMatch(s.substring(1), p.substring(1));
        } else {
            int len = s.length();

            int i = -1;
            while (i < len && (i < 0 || p.charAt(0) == '.' || p.charAt(0) == s.charAt(i))) {
                if (isMatch(s.substring(i+1), p.substring(2))) {
                    return true;
                }
                i++;
            }
            return false;
        }
    }
}
