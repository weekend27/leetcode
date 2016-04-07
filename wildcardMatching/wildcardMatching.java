// Source : https://leetcode.com/problems/wildcard-matching/
// Author : weekend27
// Date   : 2016-04-07

/**********************************************************************************

Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false

**********************************************************************************/

// How to do it:
// ref: https://leetcode.com/discuss/10133/linear-runtime-and-constant-space-solution
// time complexity O(mn)


public class Solution {
    public boolean isMatch(String s, String p) {
        int sIndex = 0, pIndex = 0, matchIndex = 0, startIndex = -1;
        while (sIndex < s.length()) {
            // advancing both pointers
            if (pIndex < p.length() && (p.charAt(pIndex) == '?' || p.charAt(pIndex) == s.charAt(sIndex))) {
                sIndex++;
                pIndex++;
            }
            // * found, only advancing pattern pointer
            else if (pIndex < p.length() && p.charAt(pIndex) == '*') {
                startIndex = pIndex;
                matchIndex = sIndex;
                pIndex++;
            }
            // last pattern pointer was *, advancing string pointer
            else if (startIndex != -1) {
                pIndex = startIndex + 1;
                matchIndex++;
                sIndex = matchIndex;
            }
            // current pattern pointer is not *, last pattern pointer was not *, NOT matching
            else {
                return false;
            }
        }

        // check for remaining characters in pattern
        while (pIndex < p.length() && p.charAt(pIndex) == '*')
            pIndex++;

        return pIndex == p.length();
    }
}
