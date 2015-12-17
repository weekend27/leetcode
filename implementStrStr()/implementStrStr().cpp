// Source : https://leetcode.com/problems/implement-strstr/
// Author : weekend27
// Date   : 2015-12-17

/**********************************************************************************

Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

**********************************************************************************/

// How to do it:
// Brute Force
// time complexity O(n*n)


class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();
        int i, j;
        for (i = 0; i <= m-n; i++){
            for (j = 0; j < n && haystack[i+j] == needle[j]; j++);
            if (j == n){
                return i;
            }
        }
        return -1;
    }
};
