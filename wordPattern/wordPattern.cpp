// Source : https://leetcode.com/problems/word-pattern/
// Author : weekend27
// Date   : 2015-12-21

/**********************************************************************************

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

**********************************************************************************/

// How to do it:
// ref: https://leetcode.com/discuss/62476/short-c-read-words-on-the-fly
/*
首先想到就是用哈希表来做，建立模式字符串中每个字符和单词字符串每个单词之间的映射，而且这种映射必须是一对一关系的，不能'a‘和’b'同时对应‘dog'。
所以我们在碰到一个新字符时，首先检查其是否在哈希表中出现，若出现，其映射的单词若不是此时对应的单词，则返回false。
如果没有在哈希表中出现，我们还要遍历一遍哈希表，看新遇到的单词是否已经是哈希表中的映射，如果没有，再跟新遇到的字符建立映射。
*/


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> m;
        istringstream in(str);
        int i = 0;
        for (string word; in >> word; ++i){
            if (m.find(pattern[i]) != m.end()){
                if (m[pattern[i]] != word){
                    return false;
                }
            }
            else {
                for (unordered_map<char, string>::iterator it = m.begin(); it != m.end(); ++it){
                    if (it->second == word){
                        return false;
                    }
                }
                m[pattern[i]] = word;
            }
        }
        return i == pattern.size();
    }
};
