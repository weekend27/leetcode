// Source : https://leetcode.com/problems/length-of-last-word/
// Author : weekend27
// Date   : 2015-12-16

/**********************************************************************************

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.

**********************************************************************************/

// How to do it:
// from the end to count, pretty easy


class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        int cnt = 0;
        for (int i = len - 1; i >= 0; i--){
            if (s[i] == ' '){
                if (cnt == 0){
                    continue;
                } else {
                    return cnt;
                }
            }
            cnt++;
        }
        return cnt;
    }
};
