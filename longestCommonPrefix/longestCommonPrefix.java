// Source : https://leetcode.com/problems/longest-common-prefix/
// Author : weekend27
// Date   : 2016-04-26

/**********************************************************************************

Write a function to find the longest common prefix string amongst an array of strings.

**********************************************************************************/

// How to do it:
// traverse the string array, use the current prefix to map the next string in order to produce a new prefix


public class Solution {
    public String longestCommonPrefix(String[] strs) {
        // case condition
        if (strs == null | strs.length == 0) {
            return "";
        }

        String pre = strs[0];
        for (int i = 1; i < strs.length; ++i) {
            while (!strs[i].startsWith(pre)) {      // current string does not have the prefix, so minimize the prefix until it becomes the prefix
                pre = pre.substring(0, pre.length() - 1);
            }
        }
        return pre;
    }
}
