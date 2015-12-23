// Source : https://leetcode.com/problems/substring-with-concatenation-of-all-words/
// Author : weekend27
// Date   : 2015-12-23

/**********************************************************************************

You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

**********************************************************************************/

// How to do it:
// ref: http://bangbingsyb.blogspot.sg/2014/11/leetcode-substring-with-concatenation.html
/*
和strStr那题的双指针解法类似。关键在于如何判断以任意i起始的S的substring是否整个L的concatenation。这里显然要用到hash table。
由于L中可能存在重复的word，所以hash table的key = word，val = count of the word。

在建立好L的hash table后，对每个S[i]进行检查。这里的一个技巧建立一个新的hash table记录已经找到的word。
因为L的hash table需要反复利用，不能被修改，并且如果以hash table作为参数进行值传递的化，时间空间消耗都很大。
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> allPos;
        if (words.empty()){
            return allPos;
        }

        int totalWords = words.size();
        int wordSize = words[0].size();
        int totalLen = wordSize * totalWords;
        if (s.size() < totalLen){
            return allPos;
        }

        unordered_map<string, int> wordCount;
        for (int i = 0; i < totalWords; i++){
            wordCount[words[i]]++;
        }

        for (int i = 0; i <= s.size()-totalLen; i++){
            if (checkSubstrings(s, i, wordCount, wordSize, totalWords)){
                allPos.push_back(i);
            }
        }
        return allPos;
    }

    bool checkSubstrings(string s, int start, unordered_map<string, int>& wordCount, int wordSize, int totalWords){
        if (s.size()-start + 1 < wordSize * totalWords){
            return false;
        }
        unordered_map<string, int> wordFound;

        for (int i = 0; i < totalWords; i++){
            string currWord = s.substr(start + i * wordSize, wordSize);
            if (!wordCount.count(currWord)){
                return false;
            }
            wordFound[currWord]++;
            if (wordFound[currWord] > wordCount[currWord]){
                return false;
            }
        }
        return true;
    }
};
