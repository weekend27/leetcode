// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author : weekend27
// Date   : 2015-12-23

/**********************************************************************************

Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

**********************************************************************************/

// How to do it:
// Generate an array to record the last position of current character.
// Count and update the left bound, and calculate the maximum.
// It will just cost constant space.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0, left = 0;
        int sl = s.length();
        int prev[300];
        memset(prev, -1, sizeof(prev));

        for (int i = 0; i < sl; i++){
            if (prev[s[i]] >= left){
                left = prev[s[i]] + 1;
            }
            prev[s[i]] = i;
            maxLen = max(maxLen, i - left + 1);
        }
        return maxLen;
    }
};
