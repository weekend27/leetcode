// Source : https://leetcode.com/problems/longest-palindromic-substring/
// Author : weekend27
// Date   : 2016-04-11

/**********************************************************************************

Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

**********************************************************************************/

// How to do it:
// see the code

public class Solution {
    private int lo, maxLen;
    public String longestPalindrome(String s) {
        if (s.length() < 2) {
            return s;
        }

        for (int i = 0; i < s.length() - 1; ++i) {
            extendPalindrome(s, i, i);      // assume odd length
            extendPalindrome(s, i, i+1);    // assume even length
        }
        return s.substring(lo, lo + maxLen);
    }

    private void extendPalindrome(String s, int j, int k) {
        while (j >= 0 && k < s.length() && s.charAt(j) == s.charAt(k)) {
            j--;
            k++;
        }
        if (maxLen < k - j - 1) {
            lo = j + 1;
            maxLen = k - j - 1;
        }
    }
}
