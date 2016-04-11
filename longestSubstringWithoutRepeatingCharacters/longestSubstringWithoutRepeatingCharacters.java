// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author : weekend27
// Date   : 2016-04-11

/**********************************************************************************

Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

**********************************************************************************/

// How to do it:
// ref:https://leetcode.com/discuss/23883/11-line-simple-java-solution-o-n-with-explanation
// hashmap, The variable "j" is used to indicate the index of first character of this substring.
// If the repeated character's index is less than j itself,
// which means the repeated character in the hash map is no longer available this time


public class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() == 0) return 0;
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        int max = 0;
        for (int i = 0, j = 0; i < s.length(); ++i) {
            if (map.containsKey(s.charAt(i))) {
                j = Math.max(j, map.get(s.charAt(i))+1);
            }
            map.put(s.charAt(i), i);
            max = Math.max(max, i-j+1);
        }
        return max;
    }
}
