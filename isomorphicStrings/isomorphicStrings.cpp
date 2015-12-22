// Source : https://leetcode.com/problems/isomorphic-strings/
// Author : weekend27
// Date   : 2015-12-22

/**********************************************************************************

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.

**********************************************************************************/

// How to do it:
// ref: http://yucoding.blogspot.sg/2015/06/leetcode-question-isomorphic-strings.html
/*
Using hashmap (dict for python) is a good idea solving this problem, since the two strings require some unique mapping.
Note that it also requires no two characters may map to the same char, e.g., s="ab", t = "aa", when we check 'b' in s, although the key 'b' has not been in the map (dict for python), its value 'a' has already been used previously. So, in our implementation, we need to take care of this issue.
Here I use two maps to store s->t mapping and t->s mapping, only when both maps has no key/value pairs, new pair is added to maps.
*/


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> map1;
        map<char, char> map2;
        for (int i = 0; i < s.size(); i++){
            if (map1.find(s[i]) == map1.end() && map2.find(t[i]) == map2.end()){
                map1[s[i]] = t[i];
                map2[t[i]] = s[i];
            }
            else {
                if (map1[s[i]] != t[i] || map2[t[i]] != s[i]){
                    return false;
                }
            }
        }
        return true;
    }
};
